import sys
import random
import json
from pathlib import Path

if (len(sys.argv) < 2):
    raise RuntimeError("Insufficient input")

NAMES = {
    "firstnames" : [
        "Aarav","Vivaan","Aditya","Rohan","Arjun","Kunal","Rahul","Siddharth","Nikhil","Aman",
        "Priya","Ananya","Kavya","Riya","Neha","Pooja","Simran","Ishita","Aditi","Sneha",
    ],
    "lastnames" : [
        "Sharma","Patel","Verma","Gupta","Mehta","Singh","Khanna","Malhotra","Jain","Kapoor",
        "Miller","Brown","Wilson","Anderson","Taylor","Thomas","Harris","Clark","Lewis","Walker",
    ]
}

LOWERCHARS = "abcdefghijklmnopqrstuvwxyz"
UPPERCHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"


namesFileName=str(Path.cwd()) + "/input/names.json"
fileName = "input-data"
size = 10 # 1..200
times = 1
types = [("int",False)] # name,int,float,charLower,charUpper,firstName,lastName
names = ["int"]

def doesWantUnique(t:str)->bool:
    if (len(t.split("-")) < 2):
        return False
    if (t.split("-")[1] == "unique"):
        return True
    return False

def genInp(tp):
    match tp:
        case "name":
            inputfirstnames = random.choices(NAMES["firstnames"],k=size)
            inputlastnames = random.choices(NAMES["lastnames"],k=size)
            return [f"{inputfirstnames[i]} {inputlastnames[i]}" for i in range(size)]
        case "firstName":
            return random.choices(NAMES["firstnames"],k=size)
        case "lastName":
            return random.choices(NAMES["lastnames"],k=size)
        case "int":
            if (unique):
                return random.sample(range(20,size+21),k=size)
            else :
                return random.choices(range(20,41),k=size)

        case "float":
            low=20
            high=40
            if (unique):
                values = set()
                while len(values) < size:
                    values.add(round(random.uniform(low, size+low+1),2))
                
                return list(values)
            else :
                return [round(random.random() * (high - low) + low,2)for _ in range(size)]

        case "charLower":
            return random.choices(LOWERCHARS,k=size)
        case "charUpper":
            return random.choices(UPPERCHARS,k=size)

def writeRowsToFile(inputs: list, fileName: str) -> None:   
    with open(fileName, 'w') as json_file:
        json.dump(inputs, json_file,indent=4)

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
inputs = {}

for i,(t,unique) in enumerate(types):
    tempInputs = genInp(t)
    inputs[names[i]] = tempInputs

fileName+=f"-{size}-size"

writeRowsToFile(inputs,str(Path.cwd())+f"/input/{fileName}.json")
print(f"./input/{fileName}.json")