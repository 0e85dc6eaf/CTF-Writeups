# Just Keyp Trying

> Here's an interesting capture of some data. But what exactly is this data? Take a look: data.pcap

Hints:

> Find out what kind of packets these are. What does the info column say in Wireshark/Cloudshark?

> What changes between packets? What does that data look like?

> Maybe take a look at http://www.usb.org/developers/hidpage/Hut1_12v2.pdf?

We can notice that data.pcap contains USB packets which doesn't look as they store anything important. If we think a bit longer (or look at the title) we can notice that the device could be keyboard as then we could store the flag as keypress events.
In the documentation from hints there is really nice table with all codes and from [this website](https://docs.mbed.com/docs/ble-hid/en/latest/api/md_doc_HID.html) we can learn what does each byte mean in the "leftover capture data" section.
```
[modifier, reserved, Key1, Key2, Key3, Key4, Key6]
```
Modifier 0x20 means `right shift` and 0x01 is `left ctrl`. With this knowledge we can easily reconstruct the flag.

Below all non-zero packets with their meaning (I removed trailing zeroes and packets with modifier only)
```
00 00 09 f
00 00 0f l
00 00 04 a
00 00 0a g
20 00 2f {
00 00 13 p
00 00 15 r
00 00 20 3
00 00 22 5
00 00 22 5
20 00 2d _
00 00 27 0
00 00 11 n
00 00 1a w
00 00 04 a
00 00 15 r
00 00 07 d
00 00 16 s
20 00 2d _
00 00 20 3
00 00 04 a
00 00 1e 1
00 00 27 0
00 00 1e 1
00 00 20 3
00 00 21 4
00 00 08 e 
20 00 30 }
01 00 06 ctrl+c
```

The flag is `flag{pr355_0nwards_3a10134e}`.