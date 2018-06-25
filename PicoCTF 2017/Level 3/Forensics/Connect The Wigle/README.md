# Connect The Wigle

> Identify the data contained within wigle and determine how to visualize it.

Hints:

> Perhaps they've been storing data in a database. How do we access the information?

> How can we visualize this data? Maybe we just need to take a step back to get the big picture?

> Try zero in the first word of the flag, if you think it's an O.

> If you think you're super close, make a private piazza post with what you think it is.

This one was actually the most difficult forensics problem in my opinion. Identifying the file was trivial as it starts with `SQLite format 3`.
When we parse the file we can notice three tables: `android_metadata`, `network` and `location`, which tells us that it comes from an android application.
I searched for the Wigle in DuckDuckGo and found out that the application called Wigle really exists. 
Unfortunately my solution was totally an overkill and what's even worse it didn't work. I created account on Wigle and downloaded their app on AndroidX86 VM. It said that there are missing 3 columns in the database so i modified it and tried again.
This time it loaded successfully. But it didn't give me anything. I tried to force app to draw on the map only networks from my database, unfortunately when I checked this option it didn't show me anything...

Fortunately there is an easier solution. We know that we want to see this networks as points on map, but we don't have to this via Wigle app. We can use any app which can draw the coordinates.
First we need to write a [script](index.php) which will convert the database to csv file containing coordinates and then we have to search for a website meeting our requirements.
Personally I used [this website](http://itools.subhashbose.com/grapher/index.php) as it includes many options which allow us to make the flag more readable.

[My config](Graph.sbgf)

[Result](result.png)

The flag is `FLAG{F0UND_M3_33DE7930}`.
