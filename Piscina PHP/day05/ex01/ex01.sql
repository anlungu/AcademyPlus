CREATE TABLE ft_table (
	id int PRIMARY KEY AUTO_INCREMENT NOT NULL,
	login varchar(11) DEFAULT `toto` NOT NULL,
	groupe ENUM('staff', 'student', 'other') NOT NULL,
	date_of_creation DATE NOT NULL
);