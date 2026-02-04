from pathlib import Path
import sys
import pandas as pd
import json

if (len(sys.argv) < 2):
    raise RuntimeError("Insufficient input")

filename = ""
datasetId = None
columnscount = 7
saveFileType = "csv"
refresh=False
size = -1

for i in range(1,len(sys.argv)):
    label,value = sys.argv[i].split(":")
    if (label == "id"):
        datasetId = int(value)
    elif (label == "filename"):
        filename = value
    elif (label == "savefiletype"):
        saveFileType = value
    elif (label == "columnscount"):
        columnscount = int(value)
    elif (label == "refresh"):
        refresh == bool(value)
    elif (label == "size"):
        size = int(value)

path = Path("data/"+filename+"."+saveFileType)

if(filename == ""):
    print("filename required")
    exit(1)

if (not refresh and path.exists()):
    print("data already fetched")
    exit(0)

if (datasetId == None):
    print("dataset id not passed")
    exit(1)

from ucimlrepo import fetch_ucirepo
df_main:pd.DataFrame = fetch_ucirepo(id=datasetId)
df:pd.DataFrame = df_main.data.original.iloc[:,:columnscount]
df = df.dropna()

match(saveFileType):
    case "csv":
        df.to_csv("data/"+filename+".csv",index=False)
    case "json":
        df.to_json("data/"+filename+".json",orient="values")
        