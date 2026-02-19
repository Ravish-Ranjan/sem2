import sys
import random
import json
from pathlib import Path

if (len(sys.argv) < 2):
    raise RuntimeError("Insufficient input")

size = 10
fileName = "input-data"
refresh = False

for i in range(1,len(sys.argv)):
    label,value = sys.argv[i].split(":")
    if (label == "size"):
        size = int(value)
    elif (label == "filename"):
        fileName = value
    elif (label == "refresh"):
        refresh = True

allCarData = []

if (not refresh and Path(f"input/{fileName}-{size}-size.json").exists()):
    print(f"./input/{fileName}-{size}-size.json")
    exit(0)

with open("data/cardata.json","r") as dataset:
    allCarData = json.load(dataset)
    
    
selectedData = random.choices(allCarData,k=size)

fileName+=f"-{size}-size"

def writeRowsToFile(inputs: list, fileName: str) -> None:  
    with open(fileName, 'w') as json_file:
        json.dump(inputs, json_file,indent=4)

writeRowsToFile(selectedData,str(Path.cwd())+f"/input/{fileName}.json")
print(f"./input/{fileName}.json")