ch = input("Are you sure (Y/n): ")
if (ch != "Y"):
    exit(0)


import mysql.connector
import json

with open("placeholder.json","r") as fob:
    data = json.load(fob)

CON = mysql.connector.connect(
    host="localhost",
    user="root",
    password="wrogn",
    database="hooman"
)

cur = CON.cursor()

cur.execute("SELECT * FROM office")
myresult = cur.fetchall()

if (len(myresult) >= len(data["office"]) ):
    print("Database already seeded")
    exit(0)


office_qry = "INSERT INTO office (location) value "

temp = ["(%s)"]*len(data["office"])
office_qry += ",".join(temp)
office_qry += ";"

cur.execute(office_qry,data["office"])

CON.commit()

print(cur.rowcount, "record inserted.")