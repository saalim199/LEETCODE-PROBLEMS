# Write your MySQL query statement below
SELECT S.user_id, round(avg(IF(C.action='confirmed',1,0)),2) as confirmation_rate FROM
Signups as S LEFT JOIN Confirmations as C ON S.user_id=C.user_id GROUP BY S.user_id