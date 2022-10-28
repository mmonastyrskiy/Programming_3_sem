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

```
### Задание 2 
```SQL

```

### Задание 3 
```SQL

```
### Задание 4 
```SQL

```

### Задание 5
```SQL

```

### Задание 6 
```SQL

```

### Задание 8 
```SQL

```


## Вариант 3 

### Задание 1 
```SQL

```
### Задание 2 
```SQL

```

### Задание 3 
```SQL

```
### Задание 4 
```SQL

```

### Задание 5
```SQL

```

### Задание 6 
```SQL

```

### Задание 8 
```SQL

```


## Вариант 4 

### Задание 1 
```SQL

```
### Задание 2 
```SQL

```

### Задание 3 
```SQL

```
### Задание 4 
```SQL

```

### Задание 5
```SQL

```

### Задание 6 
```SQL

```

### Задание 8 
```SQL

```



## Вариант 5 

### Задание 1 
```SQL

```
### Задание 2 
```SQL

```

### Задание 3 
```SQL

```
### Задание 4 
```SQL

```

### Задание 5
```SQL

```

### Задание 6 
```SQL

```

### Задание 8 
```SQL

```



## Вариант 6 

### Задание 1 
```SQL

```
### Задание 2 
```SQL

```

### Задание 3 
```SQL

```
### Задание 4 
```SQL

```

### Задание 5
```SQL

```

### Задание 6 
```SQL

```

### Задание 8 
```SQL

```





## Вариант 7 

### Задание 1 
```SQL

```
### Задание 2 
```SQL

```

### Задание 3 
```SQL

```
### Задание 4 
```SQL

```

### Задание 5
```SQL

```

### Задание 6 
```SQL

```

### Задание 8 
```SQL

```
