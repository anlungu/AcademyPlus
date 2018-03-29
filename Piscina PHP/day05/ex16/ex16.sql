SELECT count(DISTINCT id_film) AS movies FROM member_history
WHERE date BETWEEN '10/30/2006' AND '07/27/2007'
OR extract(DAY FROM date) = 24 AND extract(MONTH FROM date) = 12;