
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
CREATE OR REPLACE FUNCTION spiral() RETURNS table(f1 integer, f2 integer, f3 integer, f4 integer, f5 integer)  as $$
DECLARE
i1 INTEGER;
i2 INTEGER;
i3 INTEGER;
i4 INTEGER;
i5 INTEGER;
BEGIN
CREATE SEQUENCE indexer INCREMENT 1 MAXVALUE 5 START WITH 1 CYCLE CACHE 1;
CREATE SEQUENCE filler INCREMENT 1 MAXVALUE 5000 NO CYCLE CACHE 10 START WITH 1 ;
PERFORM nextval('filler');
PERFORM nextval('indexer');

WHILE currval('filler') <> 5000 LOOP
WHILE currval('indexer') <= 5 LOOP

IF currval('indexer') = 1 THEN
i1 = currval('filler');
PERFORM nextval('indexer');
PERFORM nextval('filler');

ELSIF currval('indexer') = 2 THEN
i2 = currval('filler');
PERFORM nextval('indexer');
PERFORM nextval('filler');

ELSIF currval('indexer') = 3 THEN
i3 = currval('filler');
PERFORM nextval('indexer');
PERFORM nextval('filler');

ELSIF currval('indexer') = 4 THEN
i4 = currval('filler');
PERFORM nextval('indexer');
PERFORM nextval('filler');


ELSIF currval('indexer') = 5 THEN
i5 = currval('filler');
PERFORM nextval('indexer');
PERFORM nextval('filler');



END IF;
END LOOP;
$1 = i1;
$2 = i2;
$3 = i3;
$4 = i4;
$5 = i5;

END LOOP;
END
$$
LANGUAGE plpgsql;
SELECT spiral();
