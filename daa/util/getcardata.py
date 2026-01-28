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

with open("data/cardata.csv","r") as dataset:
    for carData in dataset:
        carData = carData.rstrip()
        carName,horsePower = carData.rsplit(",",1)
        allCarData.append((carName.replace('"',""),float(horsePower)))
    
selectedData = random.choices(allCarData,k=size)
cars,hps = list(zip(*selectedData))
formattedData = {
    "carname":cars,
    "horsepower":hps
}

fileName+=f"-{size}-size"

def writeRowsToFile(inputs: list, fileName: str) -> None:   
    with open(fileName, 'w') as json_file:
        json.dump(inputs, json_file,indent=4)

writeRowsToFile(formattedData,str(Path.cwd())+f"/input/{fileName}.json")
print(f"./input/{fileName}.json")