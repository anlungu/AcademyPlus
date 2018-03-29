<?php

class UnholyFactory {
	private $units = array();

	public function absorb($target) {
		if (get_parent_class($target))
		{
			if (isset($this->units[$target->getName()]))
				print ("(Factory already absorbed a fighter of type " . $target->getName() . ")" . PHP_EOL);
			else {
				print ("(Factory absorbed a fighter of type " . $target->getName() . ")" . PHP_EOL);
				$this->units[$target->getName()] = $target;
			}
		}
		else
			print ("(Factory can't absorb this, it's not a fighter)" . PHP_EOL);
	}

	public function fabricate($target) {
		if (array_key_exists($target, $this->units)) {
			print ("(Factory fabricates a fighter of type " . $target . ")" . PHP_EOL);
			return (clone $this->units[$target]);
		}
		print ("(Factory hasn't absorbed any fighter of type " . $target . ")" . PHP_EOL);
		return null;
	}
}

?>