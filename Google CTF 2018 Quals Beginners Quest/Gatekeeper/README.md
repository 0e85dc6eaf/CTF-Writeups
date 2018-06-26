# Gatekeeper

This time we got an application. If we run `strings` on it we can see 
```
Usage: %s <username> <password>
 ~> Verifying.
0n3_W4rM
 ~> Incorrect username
zLl1ks_d4m_T0g_I
Correct!
Welcome back!
CTF{%s}
```
`zLl1ks_d4m_T0g_I` looks like a flag, but it is reversed. `I_g0T_m4d_sk1lLz` looks much better.

Flag: `CTF{I_g0T_m4d_sk1lLz}`