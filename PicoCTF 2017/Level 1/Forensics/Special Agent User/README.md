# Special Agent User

> We can get into the Administrator's computer with a browser exploit. But first, we need to figure out what browser they're using. Perhaps this information is located in a network packet capture we took: data.pcap. Enter the browser and version as "BrowserName BrowserVersion". NOTE: We're just looking for up to 3 levels of subversions for the browser version (ie. Version 1.2.3 for Version 1.2.3.4) and ignore any 0th subversions (ie. 1.2 for 1.2.0)

Hints:

> Where can we find information on the browser in networking data? Maybe try reading up on user-agent strings.

When we look at data.pcap with Wireshark and apply HTTP filter we can see that most of the packets were sent using wget command (user agent header begins with Wget). However there is one sent by browser and this one interests us the most.
Let's check the User-Agent HTTP header. In this case it's `Mozilla/5.0 (Macintosh; Intel Mac OS X 10.6; rv:25.0) Gecko/20100101 Firefox/25.0`. At the end of the header we can find browser name and version.

The flag is: `Firefox 25.0`