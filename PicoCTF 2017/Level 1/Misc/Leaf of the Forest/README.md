# Leaf of the Forest

> We found an even bigger directory tree hiding a flag starting at /problems/d9fbdb968961f708989999193aaca05d. It would be impossible to find the file named flag manually...

Hints:

> Is there a search function in Linux? Like if I wanted to 'find' something...

```
<username>@shell-web:/problems/d9fbdb968961f708989999193aaca05d$ find -name flag  
./forest/tree3bd8a8/trunkc5a8/trunkc874/trunkb0d5/trunk989b/trunkd500/trunk68dc/trunkd705/
branchc164/flag
<username>@shell-web:/problems/d9fbdb968961f708989999193aaca05d$ cat ./forest/tree3bd8a8/trunkc5a8/trunkc874/trunkb0d5/trunk989b/trunkd500/trunk68dc/trunkd705/branchc164/flag          
e553af78ff1f7a6a428456ac53d837e5
```

The flag is `e553af78ff1f7a6a428456ac53d837e5`.