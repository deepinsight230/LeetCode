# Write your MySQL query statement below
SELECT e.employee_id FROM Employees e
LEFT JOIN Salaries s ON (e.employee_id = s.employee_id) WHERE s.salary IS NULL
UNION
SELECT s.employee_id FROM Employees e
RIGHT JOIN Salaries s ON (e.employee_id = s.employee_id) WHERE e.employee_id IS NULL
ORDER BY 1