import sys
from matplotlib import pyplot as plt
from pathlib import Path

if (len(sys.argv) < 2):
    raise RuntimeError("Insufficient input")

data = {
    "x":[10,20,30,40,50,60,70,80,90,100]
}
xLable = "Input Size"
yLabel = "Count"
title = "Algorithm Analysis"
fileName = f"{title}"

for i in range(1,len(sys.argv)):
    dataLabel,dataValues = sys.argv[i].strip().split(":")
    if (dataLabel not in ["xLabel","yLabel","title","filename"]):
        data[dataLabel] = list(map(float,dataValues.split(",")))
    elif dataLabel == "xLabel":
        xLable = dataValues
    elif dataLabel == "yLabel":   
        yLabel = dataValues
    elif dataLabel == "title":
        title = dataValues
        fileName = dataValues
    elif dataLabel == "filename":
        fileName = dataValues

maxlen = max(len(data[k]) for k in data if k != "x")
nan = float("nan")

for i in data:
    if (i != "x"):
        data[i] += [nan]*(maxlen - len(data[i]))

x = data["x"][:maxlen]

plt.style.use("dark_background")
figure,axis = plt.subplots(figsize=(10,8))
plt.grid(True)

line_styles = ['-', '--', '-.', ':']
markers = ['o', 's', '^', 'D', 'x', '*']

prefix_style_map = {}
style_index = 0

for i in data:
    if i == "x":
        continue

    prefix = i.split("_")[0]

    if prefix not in prefix_style_map:
        prefix_style_map[prefix] = {
            "linestyle": line_styles[style_index % len(line_styles)],
            "marker": markers[style_index % len(markers)]
        }
        style_index += 1

    style = prefix_style_map[prefix]

    axis.plot(
        x,
        data[i],
        label=i,
        linestyle=style["linestyle"],
        marker=style["marker"]
    )

axis.legend()
plt.xlabel(xLable)
plt.ylabel(yLabel)
plt.title(title)

output_path = Path.cwd() / "images"
output_path.mkdir(exist_ok=True)

file_path = output_path / f"{fileName}.png"
plt.savefig(str(file_path))

print(f"./images/{fileName}.png")