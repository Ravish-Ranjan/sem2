from mysql.connector import connect

conn = connect(
    host="localhost",
    user="root",
    password="wrogn",
    database="teaches_py"
)

cur = conn.cursor()

cur.execute("select * from instructor where dept_name=%s",["History"])

res = cur.fetchall()

print("Fetched result\n")
print(f"id    \tname     \tdept_name     \tsalary")
for i in res:
    print(f"{i[0]}  \t{i[1]}  \t{i[2]}  \t{i[3]}")

conn.close()