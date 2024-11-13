SELECT DISTINCT b.email 
FROM Person a ,Person B
WHERE 
    a.id<>b.id AND 
    a.email = b.email



-- This is a better way to do it
SELECT email
FROM Person
GROUP BY email
HAVING COUNT(*)>1