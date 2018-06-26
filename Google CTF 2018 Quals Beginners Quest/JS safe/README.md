# JS safe

When we look at the open_safe() function we can see that it requires our input to be in form `CTF{[0-9a-zA-Z_@!?-]+}` and only the middle part is checked.
We can't just skip password verification, because it is used as encryption key and we'll got wrong result.
Now, let's proceed to x() function which checks if our input is valid.
I copied this function to scratchpad in Firefox, so I can easily modify it and immediately see the results.
First, let's add the following code
```js
if(/g/.test(code.substr(i,4)))
{
		console.log(i);
		console.log(env[fn]);
		console.log(env);
		console.log(code.substr(i,4));
		break;
}
```
`env[g]` contains our input, so probably nothing very important happens before it is used.
W we have to notice is that this code can not only do some calculations on numbers, but it also can create strings and functions.
The other thing is that if object property doesn't exist and we try to write something to it, JS will just add the property.

When we dump `env` object (i==876) we can see something interesting.
There is SubtleCrypto in one property and we have also digest function and `sha-256` parameter. Let's see what happens next.
```js
if(i==880)
```
In the last property we have an array of `sha-256` string and Uint8Array with our password.
It will be probably passed as an argument to digest() function.
I added some pseudo disassembly to see what's going on later.
```js
if(i>=872)
{
		console.log(i);
		console.log(lhs+"="+fn+"("+arg1+","+arg2+")")
		console.log(lhs+"="+env[fn]+"("+env[arg1]+","+env[arg2]+")")
}
if(i==980)
{
	console.log(env);
	break;
}
```
For i=940 they move hash of our input to `env[Ѿ]` and for i=960 they move first byte of it to `env[ѿ]`. Then they xor the result with 230 and `or` it to `env[h]` which is used to check if the password was correct. (`env[h]` must be zero, so all xors need to be zero too)
`xor a,b` gives 0 only if `a=b`, so we know that first byte of our hash must equal 230.
Replace our disassembler with
```js
var hash =[];
for (var i = 0; i < code.length; i += 4) {
var [lhs, fn, arg1, arg2] = code.substr(i, 4);
if(fn=='ѡ')
{
	hash.push(env[arg1][1]);
}
```
Now we know the required hash of our password ` 230,104,96,84,111,24,205,187,205,134,179,94,24,181,37,191,252,103,247,114,198,80,206,223,227,255,122,0,38,250,29,238` -> `e66860546f18cdbbcd86b35e18b525bffc67f772c650cedfe3ff7a0026fa1dee`
As they mentioned in the comment we can google for this hash and we get the password `Passw0rd!`

Flag: `CTF{Passw0rd!}`
