SELECT UPPER(user_card.last_name) AS NOM, first_name, price FROM member
INNER JOIN user_card ON member.id_user_card = user_card.id_user
INNER JOIN subscription ON subscription.id_sub = member.id_sub
WHERE price > 42
ORDER BY last_name ASC, first_name ASC;