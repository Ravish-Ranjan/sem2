import sys
import random
import json
from pathlib import Path

if (len(sys.argv) < 2):
    raise RuntimeError("Insufficient input")

NAMES = {
    "firstnames" : [
        "Adhritansh","Chandraket","Devadattan","Rajasekhar","Nagabhusan","Chandraban","Vishwambar","Padmanabha","Hariprasad","Gajananand","Mahaveeran","Aniruddhaa","Satyavrata","Venkatesha","Ravichandr","Janmejayaa","Bhupendran","Indrajeeta","Trailokyan","Kamalpreet"
    ]
}


namesFileName=str(Path.cwd()) + "/input/names.json"
fileName = "input-data"
size = 10 # 1..200
times = 1
types = [("int",False)] # firstName,int
names = ["int"]
refresh = False

def doesWantUnique(t:str)->bool:
    if (len(t.split("-")) < 2):
        return False
    if (t.split("-")[1] == "unique"):
        return True
    return False

def genInp(tp):
    match tp:
        case "firstName":
            return random.choices(NAMES["firstnames"],k=size)
        case "int":
            if (unique):
                return random.sample(range(20,size+21),k=size)
            else :
                return random.choices(range(10,21),k=size)


def writeRowsToFile(inputs: list, fileName: str) -> None:  
    toput = list(zip(*inputs.values())) 
    with open(fileName, 'w') as json_file:
        json.dump(toput, json_file,indent=4)

for i in range(1,len(sys.argv)):
    label,value = sys.argv[i].split(":")
    match (label):
        case "filename":
            fileName = value
            continue
        case "size":
            size = int(value)
            continue
        case "types":
            typeInputs = value.split(",")
            types = [(t.split("-")[0],doesWantUnique(t)) for t in typeInputs]
            continue
        case "names":
            names = value.split(",")
        case "refresh":
            refresh = True
inputs = {}

if (not refresh and Path(f"input/{fileName}-{size}-size.json").exists()):
    print(f"./input/{fileName}-{size}-size.json")
    exit(0)

for i,(t,unique) in enumerate(types):
    tempInputs = genInp(t)
    inputs[names[i]] = tempInputs

fileName+=f"-{size}-size"

writeRowsToFile(inputs,str(Path.cwd())+f"/input/{fileName}.json")
print(f"./input/{fileName}.json")