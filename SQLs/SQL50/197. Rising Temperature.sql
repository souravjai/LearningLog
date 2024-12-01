# Write your MySQL query statement below
SELECT  a.id as Id
FROM Weather a, Weather b
WHERE 
        DATEDIFF(a.recordDate,b.recordDate)  = 1
    AND
        a.temperature  > b.temperature 
