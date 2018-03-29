#!/usr/bin/php
<?PHP

function ft_split($array)
{
	$array = preg_split('/[\s]+/', $array);

	if ($array != NULL)
		sort($array);
	return ($array);
}

if ($argc > 1)
{
	$new = array();

	foreach ($argv as $arg)
	{
		if ($arg != $argv[0])
		{
			$tab = ft_split($arg);
			$new = array_merge($new, $tab);
		}
	}

	sort($new);
	foreach ($new as $e)
		echo $e."\n";
}

?>
