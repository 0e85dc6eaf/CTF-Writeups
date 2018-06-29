# Easy Pisy

This challenge is about [SHAttered attack](https://shattered.io/) on SHA1.

We are given a link to a website which either executes command of our choice or prints the text.
For security reasons the application requires pdf with instruction to be signed and it only signs PDF if it contains `ECHO` instruction.

Unfortunately (for it) it signs a hash of the PDF and it uses SHA1 for hashing.
Using [this website](http://alf.nu/SHA1) we can easily generate colliding PDFs. We need to submit 2 JPGs and it will handle the rest for us.

Then we send first PDF to sign and when we obtain valid signature, we can send the second one and execute our command.
Flag is in `flag` file.

Flag: `OOO{phP_4lw4y5_d3l1v3r5_3h7_b35T_fl4g5}`