from mysql.connector import connect

conn = connect(
    host="localhost",
    user="root",
    password="wrogn",
    database="teaches_py"
)

cur = conn.cursor()

cur.execute("""
    select I.name, T.course_id 
    from instructor I 
    join teaches T 
    on I.id=T.id
""")

res = cur.fetchall()

print("Fetched result\n")
for i in res:
    print(i)

conn.close()