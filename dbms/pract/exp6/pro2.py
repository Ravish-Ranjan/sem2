from mysql.connector import connect

conn = connect(
    host="localhost",
    user="root",
    password="wrogn",
    database="teaches_py"
)

cur = conn.cursor()

cur.execute("delete from instructor where id=%s and name=%s and dept_name=%s and salary=%s",('10211','Smith','Biology',66000))

conn.commit()

print(cur.rowcount)

conn.close()