create table database_name.table1 (
	id smallint not null autoincrement,
	code char(4) not null,
	comment varchar(255) null,
	start_time datetime
);

create table database_name.table2 (
	id smallint not null autoincrement,
	name varchar(120) not null,
	code char(4) not null,
	comment varchar(255) null,
	start_time datetime,
	table1_id smallint not null,
	subscr_qty bigint default 0,
	constraint table_rule primary key table1_id references table1(id)
);

alter table database_name add column name varchar(60) after id;

use database_name;

select * from table1, table2;

select table1.code as code1,
	table2.code as code2
from table1
inner join table2
	on table1.id = table2.table1_id
where table1.start_time > "22/01/17";

#################################################################################

define database_name;

database_name.table1 (
	num id,
	string(4) code auto,
	string comment,
	start_time time
);

database_name.table2 = database_name.table1;
database_name.table2.append(var table1_id -> table1.id, num subscr_qty auto).insert(string(60) name, id);

use database_name;

get table[1,2];
#get * from table[1,2];

#alias code1 = table1.code;
#alias code2 = table2.code;
if table1.start_time > "22/01/17"
	get code1 table1.code, code2 table2.code;