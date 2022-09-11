# Write your MySQL query statement below
SELECT u.name, IF (r.distance IS NULL, 0, SUM(r.distance)) AS travelled_distance
FROM Users u LEFT JOIN Rides r
ON u.id = r.user_id
GROUP BY u.id
ORDER BY 2 DESC, 1 ASC;