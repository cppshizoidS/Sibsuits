SELECT e.id, e.name, COUNT(*) AS count_of_employees
FROM employee AS e
JOIN department_employee AS de ON e.id = de.employee_id
JOIN department AS d ON de.department_id = d.id
GROUP BY e.id, e.name
