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
    elif dataLabel == "yLable":
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

figure,axis = plt.subplots()

for i in data:
    if (i != "x"):
        axis.plot(x,data[i],label=i)

axis.legend()
plt.xlabel(xLable)
plt.ylabel(yLabel)
plt.title(title)
plt.grid(True)

plt.savefig(str(Path.cwd())+f"/images/{fileName}.png")
print(f"./images/{fileName}.png")
