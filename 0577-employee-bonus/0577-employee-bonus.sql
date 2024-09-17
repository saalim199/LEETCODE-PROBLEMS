# Write your MySQL query statement below
SELECT name, bonus FROM Employee as E Left Join Bonus as B On E.empId=B.empId 
WHERE B.bonus<1000 or B.bonus is NULL