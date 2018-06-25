# Digital Camouflage

> We need to gain access to some routers. Let's try and see if we can find the password in the captured network data: data.pcap.

Hints:

> It looks like someone logged in with their password earlier. Where would log in data be located in a network capture?

> If you think you found the flag, but it doesn't work, consider that the data may be encrypted.

When we look at data.pcap with Wireshark we can find HTTP packet containing `application/x-www-form-urlencoded` data. In my case userid is equal to `spiveyp` and the pswrd fields equals `S04xWjZQWFZ5OQ==`.
However (as we can read in hints) we must consider that the data was encrypted. Password seems to be base64 encoded.
After decoding it we get real password - `KN1Z6PXVy9`.

The flag is: `KN1Z6PXVy9`