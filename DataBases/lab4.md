## Вариант 1 

### Задание 1 
```SQL
create table staff(
    id integer primary key,
  name varchar(64) not null,
    department varchar(64) not null
);
```
### Задание 2 
```SQL
create sequence staff_id_seq start with 12 
  cycle increment by 8 cache 100;

```

### Задание 3 
```SQL
insert into staff(id, name, department) 
  values(nextval('staff_id_seq'),'Ivan Makarenko', 'Director')
  returning *; 

```
### Задание 4 
```SQL
insert into staff(id, name, department) 
  select nextval('staff_id_seq'), last_name, 
    department_name
    from employees join departments using(department_id)
    returning *;
```

### Задание 5
```SQL
update staff set department =  'Innovations department' 
  where id < 40 returning *;
```

### Задание 6 
```SQL
delete from staff where name like '%K%' returning *;
```

### Задание 8 
```SQL
with recursive remployees(employee_id, manager_id) as
  (select employee_id, manager_id 
     from employees where employee_id = 206
   union all
   select employees.employee_id, employees.manager_id 
     from employees join remployees on remployees.employee_id = employees.manager_id)
select * from remployees;
```





## Вариант 2 

### Задание 1 
```SQL
create table deps(
id integer primary key,
name varchar(64) not null,
region varchar(64) not null
);
```
### Задание 2 
```SQL
create sequence deps_id_seq start with 31
	increment by -2
	NO CYCLE
	MAXVALUE 31;
```

### Задание 3 
```SQL
insert into deps(id, name, department) 
  values(nextval('deps_id_seq'),'Direction', 'Mars')
  returning *; 
```
### Задание 4 
```SQL
insert into deps(id, name, region) 
  select nextval('deps_id_seq'), department_name, 
    region_name
    from departments
	join locations using(location_id) join countries using(country_id) join regions using(region_id)
    returning *;
```

### Задание 5
```SQL
update deps set region = 'Europe' where region = 'Mars'
	returning *;
```

### Задание 6 
```SQL
delete from deps where id > 15
	returning *;
```

### Задание 8 
```SQL
with recursive rmanager (employee_id,manager_id) as (
select employee_id, manager_id from employees where employee_id  = 115 -- ИДшник
union all
select employees.employee_id, employees.manager_id
from employees join rmanager on rmanager.manager_id = employees.employee_id
)
select * from rmanager 
```


## Вариант 3 

### Задание 1 
```SQL
create table staff(
    id integer primary key,
  name varchar(64) not null,
    department varchar(64) not null
);
```
### Задание 2 
```SQL
create sequence staff_id_seq start with 31
	increment by 3
	NO CYCLE
	cache 10;
```

### Задание 3 
```SQL
insert into staff(id, name, department) 
  values(nextval('staff_id_seq'),'Ivan Makarenko', 'Director')
  returning *; 

```
### Задание 4 
```SQL
insert into staff(id, name, department) 
  select nextval('staff_id_seq'), first_name, 
    'Main office'
    from employees
    returning *;
```

### Задание 5
```SQL
update staff set department =  'Innovations department' 
	where name like 'I%'
	returning *;
```

### Задание 6 
```SQL
delete from staff where to_char(id,'9999999') like '%7%'
	returning *;
```

### Задание 8 
```SQL
with recursive remployees(employee_id, manager_id) as
  (select employee_id, manager_id 
     from employees where employee_id = 206
   union all
   select employees.employee_id, employees.manager_id 
     from employees join remployees on remployees.employee_id = employees.manager_id)
select * from remployees;
```


## Вариант 4 

### Задание 1 
```SQL
create table deps(
id integer primary key,
name varchar(64) not null,
region varchar(64) not null
);
```
### Задание 2 
```SQL
create sequence deps_id_seq start with 1
	increment by 4
	CYCLE;
```

### Задание 3 
```SQL
insert into deps(id, name, department) 
  values(nextval('deps_id_seq'),'Direction', 'Mars')
  returning *;
```
### Задание 4 
```SQL
insert into deps(id, name, region) 
  select nextval('deps_id_seq'), department_name, 
    substr(region_name,1,2)
    from departments
	join locations using(location_id) join countries using(country_id) join regions using(region_id)
    returning *;
```

### Задание 5
```SQL
update deps set region = 'Europe' where department_name = 'Sales'
	returning *;
```

### Задание 6 
```SQL
delete from deps where (id%2)=0;
```

### Задание 8 
```SQL
with recursive rmanager (employee_id,manager_id) as (
select employee_id, manager_id from employees where employee_id  = 115 -- ИДшник
union all
select employees.employee_id, employees.manager_id
from employees join rmanager on rmanager.manager_id = employees.employee_id
)
select * from rmanager 

```



## Вариант 5 

### Задание 1 
```SQL
create table staff(
    id integer primary key,
  name varchar(64) not null,
    department varchar(64) not null
);
```
### Задание 2 
```SQL
create sequence staff_id_seq start with 12
	increment by -8
	 CYCLE
	cache 100;
	MAXVALUE 12
```

### Задание 3 
```SQL
insert into staff(id, name, department) 
  values(nextval('staff_id_seq'),'Ivan Makarenko', 'Director')
  returning *; 
```
### Задание 4 
```SQL
insert into staff(id,name,department)
	values(nextval("staff_id_seq"),substr(first_name,1,1) || substr(last_name,1,1),
		department_name)
	from employees join departments using(department_id)
	returning *;
```

### Задание 5
```SQL
update staff set department = 'Innovations department' where id in (12,4)
	returning *;
```

### Задание 6 
```SQL
delete from staff where name = "KK"
```

### Задание 8 
```SQL
with recursive remployees(employee_id, manager_id) as
  (select employee_id, manager_id 
     from employees where employee_id = 206
   union all
   select employees.employee_id, employees.manager_id 
     from employees join remployees on remployees.employee_id = employees.manager_id)
select * from remployees;
```



## Вариант 6 

### Задание 1 
```SQL
create table deps(
id integer primary key,
name varchar(64) not null,
region varchar(64) not null
);
```
### Задание 2 
```SQL
create sequence deps_id_seq start with 31
	CYCLE
	increment by -3
	cache 10
	-- правильный порядок этаче?
```

### Задание 3 
```SQL
insert into deps(id, name, department) 
  values(nextval('deps_id_seq'),'Direction', 'Mars')
  returning *;
```
### Задание 4 
```SQL
insert into deps values(nextval("deps_id_seq"), department_name || ' ' || department_id,
region_name)
    from departments
	join locations using(location_id) join countries using(country_id) join regions using(region_id)
	returning *;

```

### Задание 5
```SQL
update deps set region = upper(substr(region,1,3))
	returning *;
```

### Задание 6 
```SQL
delete from deps where character_length(region) > 15
	returning *;
```

### Задание 8 
```SQL
with recursive rmanager (employee_id,manager_id) as (
select employee_id, manager_id from employees where employee_id  = 115 -- ИДшник
union all
select employees.employee_id, employees.manager_id
from employees join rmanager on rmanager.manager_id = employees.employee_id
)
select * from rmanager
```





## Вариант 7 

### Задание 1 
```SQL
CREATE TABLE accounts(
  account_number INTEGER PRIMARY KEY,
  person varchar(64) NOT NULL,
  percents real
  );
```
### Задание 2 
```SQL
CREATE SEQUENCE accounts_account_number_seq
  MAXVALUE 12
  start with 12 
  no cycle 
  increment by -2 
  cache 20 
  MINVALUE -1200
```

### Задание 3 
```SQL
INSERT INTO accounts(account_number, person, percents)
  VALUES(nextval('accounts_account_number_seq'), 'Ivanov Ivan Ivanovich', '7,5')
  RETURNING *;
```
### Задание 4 
```SQL
insert into accounts values(nextval('accounts_account_number_seq'),last_name || ' ' || first_name,10.0) from employees
```

### Задание 5
```SQL
UPDATE accounts SET percents = (percents/2);
```

### Задание 6 
```SQL
DELETE FROM accounts WHERE (percents < 10) AND (percents > 5);
```

### Задание 8 
```SQL
WITH recursive remployees(employee_id, manager_id) as
  (select employee_id, manager_id 
     from employees where employee_id = 206
   union all
   select employees.employee_id, employees.manager_id 
     from employees join remployees on remployees.employee_id = employees.manager_id)
select * from remployees;
```
