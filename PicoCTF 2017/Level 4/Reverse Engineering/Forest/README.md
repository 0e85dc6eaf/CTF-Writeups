# Forest

> I was wandering the forest and found a file. It came with some string

Hints:

> A number of disassemblers have tools to help view structs

When we open the binary in IDA we can see an interesting string `yuoteavpxqgrlsdhwfjkzi_cmbn` and some function which takes it as an argument.
The function loops through all characters of the string and it allocates 12 bytes per character. We can also notice that it compares is the char is greater than some previous characters.
It looks like a binary tree, so the struct is probably something like this.
```c
struct node{
	node* left;
	node* right;
	char actualchar;
}
```
The function returns address of the first character's struct and all other characters are always compared with this one, so this is our root.
We got also some mysterious [string](string.txt) file. Without further analysis of the binary we can guess that it tells us which nodes of the binary tree to chose.
L means go left, R - go right and D means that this is nth character. We can write python script that will build the binary tree and reconstruct the password.
[Final script](solve.py)
```
$ ./solve.py
you_could_see_the_forest_for_the_trees_ckyljfxyfmswy
```

The flag is `you_could_see_the_forest_for_the_trees_ckyljfxyfmswy`.
