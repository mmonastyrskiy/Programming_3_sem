
--1а
with recursive rmanager (employee_id,manager_id) as (
select employee_id, manager_id from employees where employee_id  = 6 -- ИДшник
union all
select employees.employee_id, employees.manager_id
from employees join rmanager on rmanager.manager_id = employees.employee_id
)
select * from rmanager 
--1b
create FUNCTION manager_printer() RETURNS integer $$
select * from rmanager;
return 1;
$$
