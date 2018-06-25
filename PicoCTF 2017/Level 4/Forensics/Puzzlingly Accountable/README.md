# Puzzlingly Accountable

> We need to find a password. It's likely that the updated passwords were sent over the network. Let's see if that's true: data.pcap. Update 16:26 EST 1 Apr If you feel that you are close, make a private piazza post with what you have, and an admin will help out. The ones and sevens unfortunately look like each other.

Hints:

> How does an image end up on your computer? What type of packets are involved?

When we open the file we can see it contains a lot of data.
Wireshark outputs error
```
The capture file appears to be damaged or corrupt.
(pcap: File has 1560281088-byte packet, bigger than maximum of 262144)
```

However we can still view the packets. Let's apply `http` filter. Scrolling down the packets we notice that some request contain `secret` word in the URI.
We can set filter `http.request.uri contains secret` to be more specific. Now number of packet decreased to four.
All of them are requests for some PNG files. We need to click on each packet and select `follow -> tcp stream` option.
Next select to save only response as raw data. The next step is to remove unnecessary HTTP data from the files.
Each PNG file contains some letters, but we are unable to read the flag. We can combine them into one image using IrfanView panorama feature.
Now we got our [flag](flag.png).

The flag is `5204fcd2fdde09e6a7aa730bd5d55b86`.