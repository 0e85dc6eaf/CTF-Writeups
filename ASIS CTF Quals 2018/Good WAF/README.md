# Good WAF

> WAFs cannot detect parameters filled with opaque data such as base64. Consequently, We've tuned our WAF to be more strong checking these inputs.

> Note : in order to find login endpoint, do not use brute-force,or guessing, they won't work.

> Hint : base64(jsonobject)

> [https://ctftime.org/writeup/9888]

When we visit the website, we can see that we need to provide `object` parameter which is base64 encoded JSON object.
Just for my convenience I decided to use JSON beautifier, but it quickly appeared that it also bypasses the WAF protection.
Then the challenge became an easy SQL injection task.
First we need to get tables names.
```
{
  "data": "' union select 1,group_concat(table_name) from information_schema.tables where table_schema!='information_schema'#"
}
```
It reveals that we have 3 tables: access_logs, credentials, news. We can easily dump all data from these tables using the same trick.
There is only one user - `valid_user`. Password hash in hex is 32 digits, so we know that it's probably MD5. We can easily crack the hash as the password is just `password`. The last thing we have to do is to find login panel. To do this we can simply analyse access_logs table, where we can find that someone accessed
`/?action=log-in`. When we visit this link we can see that it requires us to pass credentials array.

http://167.99.12.110/?action=log-in&credentials[0]=valid_user&credentials[1]=password

The flag is: ASIS{e279aaf1780c798e55477a7afc7b2b18}