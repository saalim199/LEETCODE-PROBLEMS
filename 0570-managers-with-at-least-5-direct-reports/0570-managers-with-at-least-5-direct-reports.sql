# Write your MySQL query statement below
SELECT e1.name FROM Employee as e1 CROSS JOIN Employee as e2 ON e1.id=e2.managerId GROUP BY e1.id HAVING count(e2.managerId)>=5