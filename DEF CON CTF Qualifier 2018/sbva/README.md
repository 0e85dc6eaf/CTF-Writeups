# sbva

When we tried to log in with given credentials, we were immediately redirected to `wrongbrowser.php`.
However when I connected with curl I was able to see some strange website before I was redirected.
```html
<html>
    <style scoped>
        h1 {color:red;}
        p {color:blue;}
    </style>
    <video id="v" autoplay> </video>
    <script>
        if (navigator.battery.charging) {
            console.log("Device is charging.")
        }
    </script>
</html>
```
I had no idea what to do with it first. I changed `User-Agent` header to `User-Agent[]` to see how it works with arrays.
I also tried to connect without `User-Agent` header, but it didn't work.

Finally I realized that probably they want us to find a browser where the above code works.
According to MDN the only browsers that support `navigator.battery` are firefox and chrome.
Newer versions only support Promise based API and property `battery` does not exist, so this code would work only for firefox 16-42 (it was removed in 50, but in 43 they introduced Promise based API).
Scoped CSS was supported in Firefox 21-54 (according to https://caniuse.com/#search=scoped). Video is fully supported since FF20.

We can't unambiguously tell which browser is the valid one, but we have only a few possibilities, so we can try them all (firefox 21-42).
In the end it worked for FF42.

[firefox42.py](firefox42.py)

Flag: `OOO{0ld@dm1nbr0wser1sth30nlyw@y}`