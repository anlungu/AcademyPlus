#!/usr/bin/php
<?PHP

if ($argc == 2)
{
	$argv[1] = preg_replace('/[\s]+/', ' ', $argv[1]);
	$argv[1] = trim($argv[1]);

	print $argv[1]."\n";
}

?>
