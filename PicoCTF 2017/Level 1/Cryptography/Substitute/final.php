<?php
$text = file_get_contents('encrypted.txt');
$key = [
'A' => 'A',
'F' => 'N',
'L' => 'S',
'M' => 'T',
'O' => 'I',
'G' => 'O',
'X' => 'V',
'T' => 'E',
'D' => 'M',
'Z' => 'B',
'K' => 'R',
'I' => 'H',
'U' => 'G',
'R' => 'D',
'B' => 'Y',
'Y' => 'F',
'C' => 'W',
'Q' => 'K',
'S' => 'L',
'E' => 'C',
'H' => 'P',
'N' => 'Z',
'W' => 'U',
'V' => 'X',
'J' => 'Q',
'P' => 'J', //unused, but only this letter left
];
for($i=0;$i<strlen($text);$i++)
{
	if( isset($key[$text[$i]]) && !empty($key[$text[$i]]) )
	{
		$text[$i] = $key[$text[$i]];
	}
	else
	{
		$text[$i] = strtolower($text[$i]);
	}
}
file_put_contents('decrypted.txt',$text);