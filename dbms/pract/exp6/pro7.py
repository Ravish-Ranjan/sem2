from mysql.connector import connect

conn = connect(
    host="localhost",
    user="root",
    password="wrogn",
    database="teaches_py"
)

cur = conn.cursor()

cur.execute("select name from instructor where salary between 90000 and 100000")

res = cur.fetchall()

print("Fetched result\n")
print("Name\n--------")
for i in res:
    print(i[0])

conn.close()