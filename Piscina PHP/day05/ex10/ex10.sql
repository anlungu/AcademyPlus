SELECT title AS Titre, summary AS Resum, prod_year AS anne_prod 
FROM film 
INNER JOIN genre ON film.id_genre = genre.id_genre AND genre.name = 'erotic' 
ORDER BY prod_year DESC;