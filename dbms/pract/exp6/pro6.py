# select name from instructor where name like "%dar%"

from mysql.connector import connect

conn = connect(
    host="localhost",
    user="root",
    password="wrogn",
    database="teaches_py"
)

cur = conn.cursor()

cur.execute("select name from instructor where name like '%dar%'")

res = cur.fetchall()

if (cur.rowcount == 0):
    print("No rows matched")
else :
    print("Fetched result\n")
    for i in res:
        print(i)
    
conn.close()