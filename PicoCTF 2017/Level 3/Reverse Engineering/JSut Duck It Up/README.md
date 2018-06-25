# JSut Duck It Up

> What in the world could this be?!?! file

Hints:

> Maybe start searching for uses of these chunks of characers? Is there anything on the Internet with them?

When we open the file we can see it contains JSFuck code. (http://www.jsfuck.com/)

We can execute it from command line or paste into JS console in the browser. In second case you'll see the alert with your flag. The first one is more interesting

```>node file
undefined:2
alert("aw_yiss_ducking_breadcrumbs_b703db4e")
^

ReferenceError: alert is not defined
```

We got the flag as well ;)

The flag is `aw_yiss_ducking_breadcrumbs_b703db4e`.