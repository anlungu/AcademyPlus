#!/usr/bin/php
<?PHP

$stdin = fopen('php://stdin', 'r');

while (true)
{
	print("Entrez un nombre: ");

	$input = trim(fgets($stdin));

	if (feof($stdin))
		exit();
	if (!is_numeric($input))
		print "'".$input."' n'est pas un chiffre\n";
	else
	{
		print "Le chiffre ".$input." est ";
		if ($input % 2 == 0)
			print "Pair\n";
		else
			print "Impair\n";
	}
}

?>
