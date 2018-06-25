<?php
$a = "eux_Z]\\ayiqlog`s^hvnmwr[cpftbkjd";
$b = "Zf91XhR7fa=ZVH2H=QlbvdHJx5omN2xc";
$c = '';
for($i = 0 ; $i < strlen($b); $i++ )
{
	$c .= $b[ ord( $a[$i] ) - 90 ];
}

echo base64_decode($c);