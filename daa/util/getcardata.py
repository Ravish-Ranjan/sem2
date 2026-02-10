import sys
import random
import json
from pathlib import Path

if (len(sys.argv) < 2):
    raise RuntimeError("Insufficient input")

size = 10
fileName = "input-data"

for i in range(1,len(sys.argv)):
    label,value = sys.argv[i].split(":")
    if (label == "size"):
        size = int(value)
    elif (label == "filename"):
        fileName = value

allCarData = []

with open("data/cardata.json","r") as dataset:
    allCarData = json.load(dataset)
    
    
selectedData = random.choices(allCarData,k=size)

fileName+=f"-{size}-size"

def writeRowsToFile(inputs: list, fileName: str) -> None:  
    with open(fileName, 'w') as json_file:
        json.dump(inputs, json_file,indent=4)

writeRowsToFile(selectedData,str(Path.cwd())+f"/input/{fileName}.json")
print(f"./input/{fileName}.json")