<?php

class Tyrion {
	public function sleepWith($o) {
		if ($o instanceof Jaime || $o instanceof Cersei)
			print ("Not even if I'm drunk !" . PHP_EOL);
		else if ($o instanceof Sansa)
			print ("Let's do this." . PHP_EOL);
	}
}

?>