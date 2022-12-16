## Вариант 1

### Задание 1
```sql
CREATE TABLE operations(
id int PRIMARY KEY,
account_number int,
operation_name text,
operation_sum double precision;

);

CREATE TABLE operations_log(
operation_id int,
account_number int,
operation_date timestamp,
operation_type char,
CHECK(operation_type in ('-','+'));
);
```
### Задание 2
```sql
--2
CREATE OR REPLACE PROCEDURE statement_of_acount(begin_date timestamp, end_date timestamp) AS $$
DECLARE
  e_attrs record;
BEGIN
  FOR e_attrs IN (SELECT operation_date, sum from people_log where operation_date <= end_date and operation_date >= begin_date and sum > 0 order by sum desc limit 3)
  LOOP
     raise info '% %', e_attrs.operation_date, e_attrs.sum;
  END LOOP;
  FOR e_attrs IN (SELECT operation_date, sum from people_log where operation_date <= end_date and operation_date >= begin_date and sum < 0 order by sum limit 3)
  LOOP
     raise info '% %', e_attrs.operation_date, e_attrs.sum;
  END LOOP;
  raise info '%', (SELECT count(*) from people_log where operation_date <= end_date and operation_date >= begin_date);
  raise info '%', (SELECT to_char(avg(sum),'FM999999999999999.99') from people_log where operation_date <= end_date and operation_date >= begin_date);
END
$$ LANGUAGE plpgsql;
call statement_of_acount('2011-09-01 00:00:0.0', '2013-05-10 00:00:0.0'); 

```
### Задание 3
```sql
CREATE OR REPLACE PROCEDURE account_operation(account_number int,id,int,operation_sum double precision) AS $$
BEGIN
IF operation_sum > 0 THEN
INSERT INTO operations VALUES(id,account_number,'внесение денег на счет',operation_sum);
END IF;
END
$$ LANGUAGE plpgsql;
```

## Вариант 2

### Задание 1
```sql
--1
CREATE TABLE people (
  id int PRIMARY KEY,
  first_name text,
  last_name text,
  birthday date,
  amount double precision 
);

CREATE TABLE people_log (
  person_id int REFERENCES people(id),
  operation_date timestamp,
  sum double precision 
);

INSERT INTO people VALUES 
(1, 'Ярослав','Лазарев','18.06.2003', 
100000), 
(2, 'Ярослав','Рыбин','13.06.2003',300), 
(3, 'Глеб','Глебов','17.03.2003',3400000), 
(4, 'Александр','Шутов','15.06.1976',980), 
(5, 'Любовь','Кельба','25.03.2003',1000), 
(6, 'Николай','Ярмолович','03.01.2003',-1000);

INSERT INTO people_log VALUES 
(3, '12.09.2011 02:28',20000), 
(2, '05.12.2011 04:20',-10000), 
(4, '07.12.2011 12:20',500000), 
(1, '01.01.2012 13:10',5000), 
(2, '05.02.2012 17:20',310000), 
(5, '05.05.2012 03:10',-30200), 
(3, '08.07.2012 11:25',-7000), 
(1, '11.10.2012 15:20',-100), 
(5, '30.12.2012 16:10',-2200);
```
### Задание 2
```sql
CREATE OR REPLACE PROCEDURE statement_of_acount(begin_date timestamp, end_date timestamp) AS $$
DECLARE
  e_attrs record;
BEGIN
  FOR e_attrs IN (SELECT operation_date, sum from people_log where operation_date <= end_date and operation_date >= begin_date and sum > 0)
  LOOP
     raise info '% %', e_attrs.operation_date, e_attrs.sum;


  END LOOP;
  FOR e_attrs IN (SELECT operation_date, sum from people_log where operation_date <= end_date and operation_date >= begin_date and sum < 0)
  LOOP
     raise info '% %', e_attrs.operation_date, e_attrs.sum;
  END LOOP;
  raise info '%', (SELECT count(*) from people_log where operation_date <= end_date and operation_date >= begin_date);
  raise info '%', (SELECT sum(sum) from people_log where operation_date <= end_date and operation_date >= begin_date and sum <0);
    raise info '%', (SELECT sum(sum) from people_log where operation_date <= end_date and operation_date >= begin_date and sum > 0);
END
$$ LANGUAGE plpgsql;
call statement_of_acount('2011-09-01 00:00:0.0', '2013-05-10 00:00:0.0'); 
```
### Задание 3
```sql
--3
CREATE OR REPLACE PROCEDURE account_operation(person_id integer, person_sum double precision) AS $$
BEGIN
  update people set amount =  amount + person_sum where id = person_id;
  INSERT INTO people_log
  VALUES (person_id, now(), person_sum);
END
$$ LANGUAGE plpgsql;
call account_operation(2, cast(250 as float)); 
select * from people_log;
select * from people;
```

## Вариант 3

### Задание 1
```sql

```
### Задание 2
```sql
CREATE OR REPLACE PROCEDURE statement_of_acount(begin_date timestamp, end_date timestamp) AS $$
DECLARE
  e_attrs record;
BEGIN
  FOR e_attrs IN (SELECT operation_date, sum from people_log where operation_date <= end_date and operation_date >= begin_date and sum > 0)
  LOOP
     raise info '% %', e_attrs.operation_date, e_attrs.sum;


  END LOOP;
  FOR e_attrs IN (SELECT operation_date, sum from people_log where operation_date <= end_date and operation_date >= begin_date and sum < 0)
  LOOP
     raise info '% %', e_attrs.operation_date, e_attrs.sum;
  END LOOP;
  raise info '%', (SELECT count(*) from people_log where operation_date <= end_date and operation_date >= begin_date);
  raise info '%', (SELECT sum(sum) from people_log where operation_date <= end_date and operation_date >= begin_date and sum <0);
    raise info '%', (SELECT sum(sum) from people_log where operation_date <= end_date and operation_date >= begin_date and sum > 0);
END
$$ LANGUAGE plpgsql;
call statement_of_acount('2011-09-01 00:00:0.0', '2013-05-10 00:00:0.0'); 
```
### Задание 3
```sql

```

## Вариант 4

### Задание 1
```sql
--1
CREATE TABLE people (
  id int PRIMARY KEY,
  first_name text,
  last_name text,
  birthday date,
  amount double precision 
);

CREATE TABLE people_log (
  person_id int REFERENCES people(id),
  operation_date timestamp,
  sum double precision 
);

INSERT INTO people VALUES 
(1, 'Ярослав','Лазарев','18.06.2003', 
100000), 
(2, 'Ярослав','Рыбин','13.06.2003',300), 
(3, 'Глеб','Глебов','17.03.2003',3400000), 
(4, 'Александр','Шутов','15.06.1976',980), 
(5, 'Любовь','Кельба','25.03.2003',1000), 
(6, 'Николай','Ярмолович','03.01.2003',-1000);

INSERT INTO people_log VALUES 
(3, '12.09.2011 02:28',20000), 
(2, '05.12.2011 04:20',-10000), 
(4, '07.12.2011 12:20',500000), 
(1, '01.01.2012 13:10',5000), 
(2, '05.02.2012 17:20',310000), 
(5, '05.05.2012 03:10',-30200), 
(3, '08.07.2012 11:25',-7000), 
(1, '11.10.2012 15:20',-100), 
(5, '30.12.2012 16:10',-2200);
```
### Задание 2
```sql
--2
CREATE OR REPLACE PROCEDURE statement_of_acount(begin_date timestamp, end_date timestamp) AS $$
DECLARE
  e_attrs record;
BEGIN
  FOR e_attrs IN (SELECT operation_date, sum from people_log where operation_date <= end_date and operation_date >= begin_date and sum > 0 order by sum desc limit 3)
  LOOP
     raise info '% %', e_attrs.operation_date, e_attrs.sum;
  END LOOP;
  FOR e_attrs IN (SELECT operation_date, sum from people_log where operation_date <= end_date and operation_date >= begin_date and sum < 0 order by sum limit 3)
  LOOP
     raise info '% %', e_attrs.operation_date, e_attrs.sum;
  END LOOP;
  raise info '%', (SELECT count(*) from people_log where operation_date <= end_date and operation_date >= begin_date);
  raise info '%', (SELECT to_char(avg(sum),'FM999999999999999.99') from people_log where operation_date <= end_date and operation_date >= begin_date);
END
$$ LANGUAGE plpgsql;
call statement_of_acount('2011-09-01 00:00:0.0', '2013-05-10 00:00:0.0'); 

```
### Задание 3
```sql
--3
CREATE OR REPLACE PROCEDURE account_operation(person_id integer, person_sum double precision) AS $$
BEGIN
  update people set amount =  amount + person_sum where id = person_id;
  INSERT INTO people_log
  VALUES (person_id, now(), person_sum);
END
$$ LANGUAGE plpgsql;
call account_operation(2, cast(250 as float)); 
select * from people_log;
select * from people;
```