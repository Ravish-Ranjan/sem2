from pathlib import Path

path = Path("data/cardata.csv")

if (path.exists()):
    print("data already fetched")
    exit(0)

from ucimlrepo import fetch_ucirepo
df_main = fetch_ucirepo(id=9)
df = df_main.data.original[["car_name","horsepower"]]
df = df.dropna()
print(df.columns)
df.to_csv("data/cardata.csv",index=False,header=False)