# disk

We got `encrypt.vmdk` file with encrypted disk.

When we run `strings encrypt.vmdk | grep rctf` on it we can see first part of the flag `rctf{unseCure_quick_form4t_vo1ume`.

Next we can use 7-zip to extract `0.fat` from `encrypt.vmdk`.

To read `0.fat` we need to use VeraCrypt. Password is `rctf` (it was given in challenge description).

There are two files on the disk `70056639_useless_file_for_ctf_just_ignore_it.jpg` and `password.txt`. Second one contains another password: `RCTF2019`.

We just need to dismount it and mount again with the new password. We may also need to select "Filesystem -> Do not mount" in options (linux).

Our disk is available at `/dev/mapper/veracrypt20` (assuming you chose 20th slot). You can use `dd if=/dev/mapper/veracrypt20 of=/home/decrypted` to copy it to file.

Now you only need to run strings on it and get second part of the flag `_and_corrupted_1nner_v0lume}`.

Flag is `rctf{unseCure_quick_form4t_vo1ume_and_corrupted_1nner_v0lume}`