-- Вариант 1
--1

CREATE TABLE operations(
id int PRIMARY KEY,
account_number int,
operation_name text,
operation_sum double precision

);

CREATE TABLE operations_log(
operation_id int,
account_number int,
operation_date timestamp,
operation_type char,
CHECK(operation_type in ('-','+'))
);

INSERT INTO operations VALUES (1, 100,'Внесение средств', 100000), (2, 200,'Снятие средств',-300),
(3, 234,'Внесение средств',3400000),
(4, 345,'Снятие средств',-980), (5, 567,'Внесение средств',1000), 
(6, 400,'Снятие средств',-1000);
INSERT INTO operations_log VALUES
(1,100,'13.06.2003','+'),
(2,200,'17.03.2003','-'),
(3,234,'15.06.1976','+'),
(4,400,'25.06.1976','-'),
(5,567,'10.02.2000','+');

--2
CREATE OR REPLACE PROCEDURE statement_of_acount(begin_date timestamp, end_date timestamp,acc_number int) AS $$
DECLARE
  e_attrs record;
BEGIN
  FOR e_attrs IN (SELECT operation_type, operation_sum,operation_date from operations_log ol join operations o using(account_number) where operation_date <= end_date and operation_date >= begin_date and o.account_number = acc_number and operation_sum > 0 order by operation_sum desc limit 3)
  LOOP
     raise info '% %', e_attrs.operation_date, e_attrs.operation_sum;
  END LOOP;
  FOR e_attrs IN (SELECT operation_type, operation_sum,operation_date from operations_log ol join operations o using(account_number) where operation_date <= end_date and operation_date >= begin_date and o.account_number = acc_number and operation_sum < 0 order by operation_sum desc limit 3)
  LOOP
     raise info '% %', e_attrs.operation_date, e_attrs.operation_sum;
  END LOOP;
  raise info '%', (SELECT count(*) from operations_log  where operation_date <= end_date and operation_date >= begin_date);
  raise info '%', (SELECT to_char(avg(operation_sum),'FM999999999999999.99') from operations o join operation_log ol where (ol.operation_date <= end_date and ol.operation_date >= begin_date));
END
$$ LANGUAGE plpgsql;

call statement_of_acount('2011-09-01 00:00:0.0', '2013-05-10 00:00:0.0',100); 

--3
CREATE OR REPLACE PROCEDURE account_operation(account_number int,id int,operation_sum double precision) AS $$
BEGIN
IF operation_sum > 0 THEN
INSERT INTO operations VALUES(id,account_number,'внесение денег на счет',operation_sum);
END
$$ 
LANGUAGE plpgsql;
