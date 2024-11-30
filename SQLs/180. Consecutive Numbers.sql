# Write your MySQL query statement below
SELECT DISTINCT a.num as ConsecutiveNums
FROM Logs a INNER JOIN Logs b INNER JOIN Logs c on a.id=b.id+1 and a.id = c.id+2
where a.num = b.num and a.num = c.num