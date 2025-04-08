from mysql.connector import connect

conn = connect(
    host="localhost",
    user="root",
    password="wrogn",
    database="teaches_py"
)

cur = conn.cursor()

cur.execute("select * from instructor cross join teaches")

res = cur.fetchall()

print("Fetched result\n")
for i in res:
    print(i)

conn.close()