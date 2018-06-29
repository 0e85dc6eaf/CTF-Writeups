# Doggo

*You have to solve pupper before this challenge*

This time the interpreter is patched and it won't allow if branches to be public if private value was used in comparison.
To solve previous challenge we didn't have to use coercion, references and functions, so probably they will be needed now.
When we play with the language for a while we can notice that we are only allowed to assign values to references.
Another important observation is that we can execute more than one instruction in functions.
It doesn't allow us yet to get the flag, becase the interpreter still claims that `A branch of an if statement may leak information`, but we are getting closer to the solution.
The last thing we have to notice is that we can coerce function to private function even if it operates on public references!
The final code looks like this. 
```
let val = ref 0 in
let f = flag in
let trueFunc = fn(x:private int) => val := 1;( 1 :> private int) in
let falseFunc = fn(x:private int) => val := 0;( 1 :> private int) in
let doNotOutput = if (flag < 0) = true
	then (trueFunc :> private (private int -> private int))(1 :> private int)
	else (falseFunc :> private (private int -> private int))(1 :> private int) in
val
```
Again we can use binary search to get the flag in reasonable amount of time.

[exploit](exploit.py)

Flag: `PCTF{$h0u1d_h4v3_f0rma11y_v3r1fi3d!}`