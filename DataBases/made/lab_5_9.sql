--lab4

--7
CREATE VIEW dep_staff_counts AS
SELECT department,count(distinct e.employee_id)ecount
FROM staff s, employees e, departments d WHERE (e.department_id = d.department_id
and d.department_name=s.department) GROUP BY department;

--lab5
--1
SELECT * FROM bd_employees where phone_number::TEXT ~* '^\d+$';

--2
SELECT * FROM bd_employees e join bd_departments deps
on(deps.id = e.department_id) where (street ~*'[^A-Z\s]');

--3
SELECT (last_name,REGEXP_REPLACE(phone_number,'^\+7','8')) FROM bd_employees;

--4a
SET ROLE POSTGRES;
REVOKE ALL ON bd_departments from my_colleague;
REVOKE ALL ON bd_employees from my_colleague;
DROP ROLE my_colleague;
CREATE ROLE my_colleague;
GRANT ALL ON bd_departments to my_colleague;

--4b
SET ROLE POSTGRES;
REVOKE ALL ON bd_employees from my_colleague;
REVOKE ALL ON bd_departments from my_colleague;
DROP ROLE my_colleague;
CREATE ROLE my_colleague;
GRANT SELECT ON bd_employees to my_colleague;

--4c
SET ROLE POSTGRES;
REVOKE ALL ON bd_employees from my_colleague;
REVOKE ALL ON bd_departments from my_colleague;
DROP ROLE my_colleague;
CREATE ROLE my_colleague;
GRANT UPDATE, DELETE ON bd_departments to my_colleague;

--5
SELECT * FROM bd_employees where (REGEXP_COUNT(last_name,'[qwrtpsdfghjklzxcvbnm\-]',1,'i')
= 2 * REGEXP_COUNT(last_name,'[aeouiy]',1,'i'));



 
SELECT last_name,
	REGEXP_REPLACE(
		REGEXP_REPLACE(
			REGEXP_REPLACE(
				REGEXP_REPLACE(
					REGEXP_REPLACE(
						REGEXP_REPLACE(
							REGEXP_REPLACE(last_name,'y',to_char(ASCII('y'),'RN'),'gi'),
							'i',to_char(ASCII('i'),'RN'),'gi'),
						'i',to_char(ASCII('i'),'RN'),'gi'),
					'u',to_char(ASCII('u'),'RN'),'gi'),
				'o',to_char(ASCII('o'),'RN'),'gi'),
			'e',to_char(ASCII('e'),'RN'),'gi'),'a',to_char(ASCII('a'),'RN'),'gi')
	
FROM bd_employees 


--6
SELECT phone_number,(REGEXP_COUNT(phone_number,'9')*9 + REGEXP_COUNT(phone_number,'8')*8 +
REGEXP_COUNT(phone_number,'7')*7 + REGEXP_COUNT(phone_number,'6')*6 +
REGEXP_COUNT(phone_number,'5')*5 + REGEXP_COUNT(phone_number,'4')*4 +
REGEXP_COUNT(phone_number,'3')*3 + REGEXP_COUNT(phone_number,'2')*2 +
REGEXP_COUNT(phone_number,'1')*1) summ FROM bd_employees;
