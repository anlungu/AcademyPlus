#!/usr/bin/php
<?PHP

$var = $_GET;

foreach ($var as $v => $e)
{
	echo $v.": ".$e."\n";
}

?>
