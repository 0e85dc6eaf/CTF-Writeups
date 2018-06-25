# Meta Find Me

> Find the location of the flag in the image: image.jpg. Note: Latitude and longitude values are in degrees with no degree symbols,/direction letters, minutes, seconds, or periods. They should only be digits. The flag is not just a set of coordinates - if you think that, keep looking!

Hints:

> How can images store location data? Perhaps search for GPS info on photos.

JPG format supports EXIF metadata where we can store a lot of interesting information. On [this website](http://www.verexif.com/en/ver.php) we can view EXIF of our image.

```
Exif data

Date/Time :
    2016/02/10 11:55:56
Resolution :
    500 x 500
Jpeg process :
    Progressive
GPS Latitude :
    ? 77º 0' 0"
GPS Longitude :
    ? 172º 0' 0"
Comment :
    "Your flag is flag_2_meta_4_me_<lat>_<lon>_736c. Now find the GPS coordinates of this image! (Degrees only please)"
```

We now only need to replace lat and lon with 77 and 172 and we get our flag.

The flag is `flag_2_meta_4_me_77_172_736c`.