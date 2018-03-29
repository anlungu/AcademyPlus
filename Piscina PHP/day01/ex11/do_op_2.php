#!/usr/bin/php
<?PHP

if ($argc != 2)
	print "Incorrect Parameters\n";
else
{
	$op = sscanf($argv[1], "%d %c %d %s");

	if ($op[0] && $op[1] && $op[2] && !$op[3])
	{
		switch ($op[1]) {
			case "+":
				$result = $op[0] + $op[2];
				break;
			case "-":
				$result = $op[0] - $op[2];
				break;
			case "*":
				$result = $op[0] * $op[2];
				break;
			case "/":
				$result = $op[0] / $op[2];
				break;
			case "%":
				$result = $op[0] % $op[2];
				break;
			default:
				print "Syntax Error\n";
				exit();
		}
	}
	else
	{
		print "Syntax Error\n";
		exit();
	}

	print $result."\n";
}

?>
