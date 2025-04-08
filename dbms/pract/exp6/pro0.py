from mysql.connector import connect

conn = connect(
    host="localhost",
    user="root",
    password="wrogn"
)

cur = conn.cursor()

cur.execute("create database if not exists teaches_py")
cur.execute("use teaches_py")

cur.execute("""
    create table if not exists instructor(
        id varchar(5) primary key unique,
        name varchar(24) not null,
        dept_name varchar(20) not null,
        salary int not null,
        unique (id)
    )
""")

cur.execute("""
    create table if not exists teaches(
        id varchar(5) not null,
        course_id varchar(20) not null,
        sec_id int not null,
        semester varchar(12) not null,
        year year not null,
        foreign key (id) references instructor (id) on delete cascade
    )
""")

instructor_data=(
    (10101,"Srinivasan","Comp. Sci.",65000),
    ("12121","Wu","Finance",90000),
    ("15151","Mozart","Music",40000),
    ("22222","Einstein","Physics",95000),
    ("32343","El Said","History",60000),
    ("33456","Gold","Physics",87000),
    ("45565","Katz","Comp. Sci.",75000),
    ("58583","Califieri","History",62000),
    ("76543","Singh","Finance",80000),
    ("76766","Crick","Biology",72000),
    ("83821","Brandt","Comp. Sci.",92000),
    ("98345","Kim","Elec. Eng.",80000)
)
teaches_data=(
    ("10101","CS-101",1,"Fall",2017),
    ("10101","CS-315",1,"Spring",2018),
    ("10101","CS-347",1,"Fall",2017),
    ("12121","FIN-201",1,"Spring",2018),
    ("15151","MU-199",1,"Spring",2018),
    ("22222","PHY-101",1,"Fall",2017),
    ("32343","HIS-351",1,"Spring",2018),
    ("45565","CS-101",1,"Spring",2018),
    ("45565","CS-319",1,"Spring",2018),
    ("76766","BIO-101",1,"Summer",2017),
    ("76766","BIO-301",1,"Summer",2018),
    ("83821","CS-190",1,"Spring",2017),
    ("83821","CS-190",2,"Spring",2017),
    ("83821","CS-319",2,"Spring",2018),
    ("98345","EE-181",1,"Spring",2017)
)

cur.executemany("insert into instructor values(%s,%s,%s,%s)",instructor_data)

cur.executemany("insert into teaches values(%s,%s,%s,%s,%s)",teaches_data)
conn.commit()

res = cur.fetchall()

print(res)

conn.close()