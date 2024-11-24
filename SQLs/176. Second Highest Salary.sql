# Write your MySQL query statement below
SELECT MAX(salary) as SecondHighestSalary 
FROM Employee 
WHERE SALARY != (SELECT  MAX(salary) from Employee)