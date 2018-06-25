<?php
function decrypt($string)
{
	$retval = '';
	for($i=0;$i<strlen($string);$i++)
	{
		if($i==0)
		{
			$retval = $string[$i];
			continue;
		}
		
		$char = ord($string[$i]) - ord($retval[$i-1]) + 32;
		if($char<32)
		{
			$char+=96;
		}
		$retval .= chr($char);
	}
	return $retval;
}
echo strrev(decrypt('tu1|\h+&g\OP7@% :BH7M6m3g='));