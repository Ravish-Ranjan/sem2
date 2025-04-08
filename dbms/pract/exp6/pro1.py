from mysql.connector import connect

conn = connect(
    host="localhost",
    user="root",
    password="wrogn",
    database="teaches_py"
)

cur = conn.cursor()

cur.execute("insert into instructor values(%s,%s,%s,%s)",("10211","Smith","Biology",66000))

conn.commit()

print(cur.rowcount)

conn.close()