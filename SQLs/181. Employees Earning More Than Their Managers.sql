SELECT a.name as Employee 
FROM Employee a
INNER JOIN Employee b ON a.managerID = b.id
WHERE a.salary>b.salary