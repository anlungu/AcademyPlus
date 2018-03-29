#!/usr/bin/php
<?PHP

if ($argc > 1)
{
	$argv[1] = preg_replace('/[\s]+/', ' ', $argv[1]);
	$argv[1] = trim($argv[1]);

	$new = explode(" ", $argv[1]);
	$tmp = array_shift($new);

	foreach($new as $n)
		print $n." ";

	print $tmp."\n";
}

?>
