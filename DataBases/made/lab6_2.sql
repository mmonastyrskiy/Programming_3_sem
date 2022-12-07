
--1а
with recursive rmanager (id,manager_id) as (
select id, manager_id from bd6_employees where id  = 6 -- ИДшник
union all
select bd6_employees.id, bd6_employees.manager_id
from bd6_employees join rmanager on rmanager.manager_id = bd6_employees.id
)
select * from rmanager;

--1b
CREATE OR REPLACE PROCEDURE manager_printer() as $$
DECLARE
i integer;
emp record;
BEGIN
i =6;
WHILE i >= 1 LOOP
FOR emp in  SELECT id,manager_id,last_name from bd6_employees where id = i LOOP
RAISE INFO 	'% %', emp.id, emp.last_name;
i  = emp.manager_id;

	END LOOP;
	END LOOP;

END
	$$
LANGUAGE plpgsql;
CALL manager_printer();
-- ИЛИ --- Если спросит рекурсивно сделать


CREATE OR REPLACE PROCEDURE remployees(e_id integer) AS $$
DECLARE 
  manager integer := (select manager_id from bd6_employees where id = e_id);
  e_last_name varchar := (select last_name from bd6_employees where id = e_id);
BEGIN
  raise info '% % %', e_id, e_last_name, manager;
  if manager is not null then
    call remployees(manager);
  end if;
END
$$ LANGUAGE plpgsql;
call remployees(6);

--2
CREATE OR REPLACE FUNCTION t2() RETURNS integer AS $$
DECLARE
curs_em CURSOR FOR select * from bd6_employees order by department_id, salary_in_euro;
person bd6_employees%ROWTYPE;
a integer;
dep numeric(38);
BEGIN
OPEN curs_em;
FETCH curs_em INTO person;
dep:=0;
while found
loop
if dep != person.department_id then dep:=person.department_id;
a:=1;
else
a:=a+1;
end if;
RAISE INFO '% % % Доб.%', person.last_name,person.first_name,
person.phone_number,a;
fetch curs_em into person;
end loop;
return 1;
END;
$$
LANGUAGE plpgsql;
SELECT t2();



--3
CREATE OR REPLACE PROCEDURE update_managers() AS $$
DECLARE
  e_attrs record;
BEGIN
  FOR e_attrs IN
    (SELECT b6.id, b.manager_id as manager2
      from bd6_employees b6 join (select b1.id, b2.manager_id from bd6_employees b1 join bd6_employees b2 on b1.manager_id = b2.id) b
       on b6.id = b.id where b6.manager_id != 1 order by b6.manager_id, b6.salary_in_euro offset 3)
  LOOP
    --raise info '% %', e_attrs.id, e_attrs.manager2;
    update bd6_employees 
    set manager_id = e_attrs.manager2 where id = e_attrs.id;
  END LOOP;
END
$$ LANGUAGE plpgsql;
call update_managers();

--4
DROP TABLE IF EXISTS spiral;
CREATE TABLE spiral( f1 integer, f2 integer, f3 integer, f4 integer, f5 integer );
CREATE OR REPLACE FUNCTION fspiral() RETURNS integer AS $$
DECLARE
i integer := 1;
n integer := 0;
BEGIN
WHILE n < 1000
LOOP
CASE mod(i,4)
WHEN 1 THEN INSERT INTO spiral VALUES (n + 1, n + 3, n + 5, n + 7, n + 9);
WHEN 2 THEN INSERT INTO spiral VALUES (n + 2, n + 4, n + 6, n + 8, n + 10);
n := n + 10;
WHEN 3 THEN INSERT INTO spiral VALUES (n + 10, n + 8, n + 6, n + 4, n + 2);
WHEN 0 THEN INSERT INTO spiral VALUES (n + 9, n + 7, n + 5, n + 3, n + 1);
n := n + 10;
END CASE;
i := i + 1;
END LOOP;
return 1;
END;
$$
LANGUAGE plpgsql;
select spiral();
SELECT * from spiral;
