<?php

class Color
{
	public $red;
	public $green;
	public $blue;
	public static $verbose = false;
	
	public function __construct( array $kwargs ) {
		if ( isset($kwargs['red']) && isset($kwargs['green']) && isset($kwargs['blue']) )
		{
			$this->red = intval($kwargs['red']);
			$this->green = intval($kwargs['green']);
			$this->blue = intval($kwargs['blue']);
		}
		else if ( isset($kwargs['rgb']) )
		{
			$rgb = intval($kwargs['rgb']);
			$this->red = $rgb / 65536 % 255;
			$this->green = $rgb / 256 % 256;
			$this->blue = $rgb % 256;
		}

		if ( self::$verbose )
			printf( "Color( red: %3d, green: %3d, blue: %3d ) constructed.\n", $this->red, $this->green, $this->blue );
	}

	public function __destruct() {
		if ( self::$verbose )
			printf( "Color( red: %3d, green: %3d, blue: %3d ) destructed.\n", $this->red, $this->green, $this->blue );
	}

	public function __toString() {
		return (sprintf( "Color( red: %3d, green: %3d, blue: %3d )", $this->red, $this->green, $this->blue ));
	}

	public function add ( $kwargs ) {
		return (new Color( array( 'red' => $this->red + $kwargs->red, 'green' => $this->green + $kwargs->green, 'blue' => $this->blue + $kwargs->blue ) ));
	}

	public function sub ( $kwargs ) {
		return (new Color( array( 'red' => $this->red - $kwargs->red, 'green' => $this->green - $kwargs->green, 'blue' => $this->blue - $kwargs->blue ) ));
	}

	public function mult ( $kw ) {
		return (new Color( array( 'red' => $this->red * $kw, 'green' => $this->green * $kw, 'blue' => $this->blue * $kw ) ));
	}

	public static function doc() {
		print "\n" . file_get_contents("./Color.doc.txt") . "\n";
	}
}

?>