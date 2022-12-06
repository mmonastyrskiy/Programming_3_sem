
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
