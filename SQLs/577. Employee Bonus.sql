# Write your MySQL query statement below

SELECT e.name,b.bonus
FROM Employee e LEFT JOIN Bonus b
ON   e.empID = b.empID
Where b.bonus IS NULL or b.bonus < 1000