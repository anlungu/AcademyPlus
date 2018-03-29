#!/usr/bin/php
<?PHP

if ($argc != 4)
	print "Incorrect Parameters\n";
else
{
	$op1 = trim($argv[1]);
	$op2 = trim($argv[3]);
	$operand = trim($argv[2]);

	switch ($operand) {
		case "+":
			$result = $op1 + $op2;
			break;
		case "-":
			$result = $op1 - $op2;
			break;
		case "*":
			$result = $op1 * $op2;
			break;
		case "/":
			$result = $op1 / $op2;
			break;
		case "%":
			$result = $op1 % $op2;
			break;
	}

	print $result."\n";
}

?>
