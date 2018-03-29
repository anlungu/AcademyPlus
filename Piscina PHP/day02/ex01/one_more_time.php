#!/usr/bin/php
<?PHP

date_default_timezone_set('Europe/Paris');

function errorexit ()
{
	print "Wrong Format\n";
	exit();
}

function inputcheck ($string)
{
	if (preg_match("/(^[L|l]undi|^[M|m]ardi|^[M|m]ercredi|^[J|j]eudi|^[V|v]endredi|^[S|s]amedi|^[D|d]imanche) {1}([0-9]{1,2}) {1}([J|j]anvier|[F|f]evrier|[M|m]ars|[A|a]vril|[M|m]ai|[J|j]uin|[J|j]uillet|[A|a]out|[S|s]eptembre|[O|o]ctobre|[N|n]ovembre|[D|d]ecembre) {1}[0-9]{4} {1}[0-9]{2}:[0-9]{2}:[0-9]{2}$/", $string) != 0)
		return (true);
	return (false);
}

function getnum ($string)
{
	if (strcasecmp($string, "janvier"))
		return (1);
	else if (strcasecmp($string, "fevrier"))
		return (2);
	else if (strcasecmp($string, "mars"))
		return (3);
	else if (strcasecmp($string, "avril"))
		return (4);
	else if (strcasecmp($string, "mai"))
		return (5);
	else if (strcasecmp($string, "juin"))
		return (6);
	else if (strcasecmp($string, "juillet"))
		return (7);
	else if (strcasecmp($string, "aout"))
		return (8);
	else if (strcasecmp($string, "septembre"))
		return (9);
	else if (strcasecmp($string, "octobre"))
		return (10);
	else if (strcasecmp($string, "novembre"))
		return (11);
	else if (strcasecmp($string, "decembre"))
		return (12);
}

if ($argc == 2)
{
	if (!inputcheck($argv[1]))
		errorexit();

	preg_match("/([0-9]{1,2})/", $argv[1], $day);
	preg_match("/([J|j]anvier|[F|f]evrier|[M|m]ars|[A|a]vril|[M|m]ai|[J|j]uin|[J|j]uillet|[A|a]out|[S|s]eptembre|[O|o]ctobre|[N|n]ovembre|[D|d]ecembre)/", $argv[1], $month);
	$mo = getnum($month[0]);
	preg_match("/[0-9]{4}/", $argv[1], $year);
	preg_match("/[0-9]{2}:/", $argv[1], $hour);
	$hour[0] = substr($hour[0], 0, 2);
	preg_match("/:[0-9]{2}:/", $argv[1], $min);
	$min[0] = substr($min[0], 1);
	$min[0] = substr($min[0], 0, 2);
	preg_match("/:[0-9]{2}$/", $argv[1], $sec);
	$sec[0] = substr($sec[0], 1, 3);

	print mktime($hour[0], $min[0], $sec[0], $mo, $day[0], $year[0])."\n";
}

?>
