#!/usr/bin/php
<?PHP

function ft_is_sort($tab)
{
	$new = $tab;
	sort($new);

	return ($tab === $new);
}

?>
