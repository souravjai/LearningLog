# Write your MySQL query statement below
SELECT s.name
FROM SalesPerson s
WHERE s.sales_id NOT IN (
    SELECT o.sales_id
    FROM Orders o
    Where o.com_id IN (SELECT c.com_id FROM Company c Where name="RED")
)