#!/usr/bin/php
<?PHP

function ft_split($array)
{

	//$array = array_map("trim", explode(" ", $array);
	$array = preg_split('/[\s]+/', $array);

	if ($array != NULL)
		sort($array);
	return ($array);
}

?>
