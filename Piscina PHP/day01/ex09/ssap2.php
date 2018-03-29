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

	foreach ($new as $e)
	{
		if (ctype_alpha($e))
			$strings[] = $e;
	}
	sort($strings, SORT_NATURAL | SORT_FLAG_CASE);

	foreach ($new as $e)
	{
		if (is_numeric($e))
			$numeric[] = $e;
	}
	sort($numeric, SORT_STRING);

	foreach ($new as $e)
	{
		if (!ctype_alpha($e) && !is_numeric($e))
			$ascii[] = $e;
	}
	sort($ascii);

	foreach ($strings as $s)
		echo $s."\n";
	foreach ($numeric as $n)
		echo $n."\n";
	foreach ($ascii as $a)
		echo $a."\n";
}

?>
