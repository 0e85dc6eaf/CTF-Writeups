# Substitute

> A wizard (he seemed kinda odd...) handed me this. Can you figure out what it says?

Hints:

> There are tools that make this easy this.

There are many tools that can solve this problem for you, but we can also do this manually.
First, let's create simple PHP script which will replace characters and convert unknown characters to lowercase.

```
<?php
$text = file_get_contents('encrypted.txt');
$key = [];
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
```

We can start with replacing some obvious characters. `L` probably stands for `S` as there are many words ending with `'L` in our ciphertext.
`OL` occurs many times so if `L` substitutes `S`, `O` would probably be `I`. We have also something like `OM'L`,so we can suspect that `M` stands for `T`.
We can find something like `AL AF` in our ciphertext and it allows us to assume that `A` stands for itself as `AL` probably replaces `AS`,`F` could be `T` or `N`, but `T` is already taken so let's consider `N`.

With this knowledge we can fill the $key array with some letters.

```
$key = [
'A' => 'A',
'F' => 'N',
'L' => 'S',
'M' => 'T',
'O' => 'I',
];
```

Running the script makes our text a bit more clear ;). We can continue our analysis.

`Ngxtdztk 21, 1985` this part would probably stand for a date. We only know the `N` letter, but we have only one month starting with `N`. So let's update our array.

```
'G' => 'O',
'X' => 'V',
'T' => 'E',
'D' => 'M',
'Z' => 'B',
'K' => 'R',
```

Now we know a big part of the text and we can try to complete the words we are already able to recognize.
`TiE` stands for `THE`, `uENERATEr` for `GENERATED`, `Bb` for `BY`, `Oy` for `OF`, `cERE` for `WERE` (as `H` is already in use), `BOOqS` for `BOOKS`,

```
'I' => 'H',
'U' => 'G',
'R' => 'D',
'B' => 'Y',
'Y' => 'F',
'C' => 'W',
'Q' => 'K',
```

Ok, it will be easier if we run script again ;) Now we are able to replace all left characters.

[Final script](final.php)

[Decrypted file](decrypted.txt)

The flag is `IFONLYMODERNCRYPTOWASLIKETHIS`.