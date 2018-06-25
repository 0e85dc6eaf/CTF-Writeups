# Lazy Dev

> I really need to login to this website, but the developer hasn't implemented login yet. Can you help?

Hints:

> Where does the password check actually occur?

> Can you interact with the javascript directly?

When we look at the page source, we can see that validating password is done client-side which is always a bad idea.

```
function validate(pword){
	//TODO: Implement me
	return false;
}
...
function make_ajax_req(input){
...
	var params = "pword_valid=" + input.toString();
...
	var res = validate(pword);
	var server_res = make_ajax_req(res);
```

The make_ajax_req function takes one parameter (a boolean) which determines if the password is correct or not, so let's open javascript console in the browser and type

```
make_ajax_req(true);
```

On the screen should appear the flag.

The flag is `client_side_is_the_dark_sidea99c64effed2c2f1c9347eff536e949c`.