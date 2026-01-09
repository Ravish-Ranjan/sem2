import sys
import random
import json


if (len(sys.argv) < 2):
    raise RuntimeError("Insufficient input")

namesFileName="/home/ravish/work/sem2/daa/util/names.json"
fileName = "input-data"
size = 10 # 1..200
types = [("int",False)] # name,int,float,charLower,charUpper,firstName,lastName

def doesWantUnique(t:str)->bool:
    if (len(t.split("-")) < 2):
        return False
    if (t.split("-")[1] == "unique"):
        return True
    return False

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
inputs = []

LOWERCHARS = "abcdefghijklmnopqrstuvwxyz"
UPPERCHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

for t,unique in types:
    match t:
        case "name":
            if (size > 200):
                raise RuntimeError("Don't have names more than 200")
            with open(namesFileName,"r") as fob:
                allName = json.load(fob)
                firstnames = allName["firstnames"]
                lastnames = allName["lastnames"]
                if (unique):
                    inputfirstnames = random.sample(firstnames,k=size)
                    inputlastnames = random.sample(lastnames,k=size)
                    inputs.append([f"{inputfirstnames[i]}-{inputlastnames[i]}" for i in range(size)])
                else :
                    inputfirstnames = random.choices(firstnames,k=size)
                    inputlastnames = random.choices(lastnames,k=size)
                    inputs.append([f"{inputfirstnames[i]}-{inputlastnames[i]}" for i in range(size)])

            continue
        case "firstName":
            if (size > 200):
                raise RuntimeError("Don't have first names more than 200")
            with open(namesFileName,"r") as fob:
                names = json.load(fob)["firstnames"]
                if (unique):
                    inputs.append(random.sample(names,k=size))
                else :
                    inputs.append(random.choices(names,k=size))

            continue
        case "lastName":
            if (size > 200):
                raise RuntimeError("Don't have last names more than 200")
            with open(namesFileName,"r") as fob:
                names = json.load(fob)["lastnames"]
                if (unique):
                    inputs.append(random.sample(names,k=size))
                else :
                    inputs.append(random.choices(names,k=size))

            continue
        case "int":
            if (unique):
                inputs.append(random.sample(range(100),k=size))
            else :
                inputs.append(random.choices(range(100),k=size))

            continue
        case "float":
            low=0
            high=100
            if (unique):
                values = set()
                while len(values) < size:
                    values.add(round(random.uniform(low, high),4))
                
                inputs.append(list(values))
            else :
                inputs.append([round(random.random() * (high - low) + low,4)for _ in range(size)])

            continue
        case "charLower":
            if (unique):
                inputs.append(random.sample(LOWERCHARS,k=size))
            else :
                inputs.append(random.choices(LOWERCHARS,k=size))
            continue
        case "charUpper":
            if (unique):
                inputs.append(random.sample(UPPERCHARS,k=size))
            else :
                inputs.append(random.choices(UPPERCHARS,k=size))
            continue


fileName+=f"-{size}-size"

def writeRowsToFile(inputs: list, fileName: str) -> None:
    rows = zip(*inputs)    
    with open(fileName, 'w') as f:
        for row in rows:
            line = ' '.join(str(item) for item in row)
            f.write(line + '\n')

writeRowsToFile(inputs,f"/home/ravish/work/sem2/daa/input/{fileName}.txt")
print(f"./input/{fileName}.txt")