#!/usr/bin/php
<?PHP

$result = NULL;

foreach ($argv as $arg)
{
	if ($arg == $argv[0] || $arg == $argv[1])
	{

	}
	else
	{
		$val = explode(":", $arg);
		if ($argv[1] == $val[0])
			$result = $val[1];
	}
}

if ($result != NULL)
	print $result."\n";

?>
