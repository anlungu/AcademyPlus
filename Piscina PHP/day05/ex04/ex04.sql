UPDATE ft_table
SET 'date_of_creation' = DATE_ADD('date_of_creation', INTERVAL 20 YEARS)
WHERE id > 5;