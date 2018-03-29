<?php

require_once 'Color.class.php';

class Vertex {
	private $_x;
	private $_y;
	private $_z;
	private $_w = 1.0;
	private $_color;
	public static $verbose = false;

	public function __construct( array $vtx ) {
		if ( isset($vtx['x']) && isset($vtx['y']) && isset($vtx['z']) )
		{
			$this->_x = floatval($vtx['x']);
			$this->_y = floatval($vtx['y']);
			$this->_z = floatval($vtx['z']);
		}

		if ( isset($vtx['w']) )
			$this->_w = floatval($vtx['w']);
		if ( isset($vtx['color']) && $vtx['color'] instanceof Color )
			$this->_color = $vtx['color'];
		else
			$this->_color = new Color( array( 'red' => 255, 'green' => 255, 'blue' => 255 ) );

		if ( self::$verbose )
			printf( "Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f, Color( red: %3d, green: %3d, blue: %3d ) ) constructed\n", $this->_x, $this->_y, $this->_z, $this->_w, $this->_color->red, $this->_color->green, $this->_color->blue );
	}

	public function __destruct() {
		if ( self::$verbose )
			printf( "Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f, Color( red: %3d, green: %3d, blue: %3d ) ) destructed\n", $this->_x, $this->_y, $this->_z, $this->_w, $this->_color->red, $this->_color->green, $this->_color->blue );
	}

	public function __toString() {
		if ( self::$verbose )
			return ( sprintf( "Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f, Color( red: %3d, green: %3d, blue: %3d ) )", $this->_x, $this->_y, $this->_z, $this->_w, $this->_color->red, $this->_color->green, $this->_color->blue ) );
		return ( sprintf( "Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f )", $this->_x, $this->_y, $this->_z, $this->_w ) );
	}

	public static function doc() {
		print "\n" . file_get_contents("./Vertex.doc.txt") . "\n";
	}
}

?>