# Write your MySQL query statement below
SELECT u.user_id AS buyer_id, u.join_date, IF(o.buyer_id IS NULL, 0, COUNT(u.user_id)) AS orders_in_2019 
FROM Users u LEFT JOIN (SELECT * FROM Orders WHERE order_date 
                   BETWEEN '2019-01-01' AND '2019-12-31') o
ON u.user_id = o.buyer_id
GROUP BY u.user_id;