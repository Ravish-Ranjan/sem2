import networkx as nx
import matplotlib.pyplot as plt
import sys

if (len(sys.argv) < 2):
    raise RuntimeError("Insufficient input")

params = {
    "title":"Graph",
    "filename":"graph",
    "directed":False,
    "istree":False
}

plot = {
    "nodes":[],
    "edges":[]
} 

plt.style.use("dark_background")

def parse(data:str):
    parts = data.split("~")
    
    if (len(parts) == 2):
        if (parts[1].isalpha()):
            return (parts[0],parts[1])
        return (parts[0],{"cost":float(parts[1])})

    if (len(parts) == 3):
        return (parts[0],parts[1],{"cost":float(parts[2])})

    return (parts[0])



for pair in sys.argv[1:]:
    key,value = pair.split(":")
    if (key in ["nodes","edges"]):
        plot[key] = [parse(n) for n in value.split(",")]
    elif (key in ["directed","istree"]):
        params[key] = value.lower() == "true"
    elif (key in ["title","filename"]):
        params[key] = value

G = None

if (params["directed"]):
    G = nx.DiGraph()
else:
    G = nx.Graph()

G.add_nodes_from(plot["nodes"])
G.add_edges_from(plot["edges"])

def hierarchy_pos(G, root, width=1., vert_gap=0.2, vert_loc=0, xcenter=0.5):
    pos = {}
    visited = set()

    def _hierarchy_pos(G, root, left, right, vert_loc, pos, parent=None):
        pos[root] = ((left + right) / 2, vert_loc)
        visited.add(root)
        children = [n for n in G.neighbors(root) if n not in visited]
        if len(children) != 0:
            dx = (right - left) / len(children)
            nextx = left
            for child in children:
                nextx += dx
                pos = _hierarchy_pos(G, child, nextx - dx, nextx, vert_loc - vert_gap, pos, root)
        return pos

    return _hierarchy_pos(G, root, 0, width, vert_loc, pos)

pos = None
if (params["istree"]):
    root_node = plot["nodes"][0][0] if isinstance(plot["nodes"][0], tuple) else plot["nodes"][0]
    pos = hierarchy_pos(G, root_node)
else:
    pos = nx.spectral_layout(G)

plt.title(params["title"])
nx.draw(G, pos, node_color="lightblue", edge_color="gray", node_size=1000, font_size=8)

node_labels = {}
for node in G.nodes(data=True):
    if 'cost' in node[1]:
        node_labels[node[0]] = f"{node[0]}\n({node[1]['cost']})"
    else:
        node_labels[node[0]] = node[0]

nx.draw_networkx_labels(G, pos, node_labels, font_size=8)

edge_labels = {}
for edge in G.edges(data=True):
    if 'cost' in edge[2]:
        edge_labels[(edge[0], edge[1])] = edge[2]['cost']

if edge_labels:
    nx.draw_networkx_edge_labels(G, pos, edge_labels, font_size=7)
plt.tight_layout()
plt.savefig(f"./images/{params['filename']}.png")

print(f"./images/{params['filename']}.png")