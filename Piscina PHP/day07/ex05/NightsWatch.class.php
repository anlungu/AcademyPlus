<?php

class NightsWatch implements IFighter {
	private $soldier = array();

	public function recruit($o) {
		$this->soldier[] = $o;
	}

	public function fight() {
		foreach($this->soldier as $s)
			if (method_exists(get_class($s), 'fight'))
				$s->fight();
	}
}

?>