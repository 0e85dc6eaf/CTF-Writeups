# Coffee

> You found a suspicious USB drive in a jar of pickles. It contains this file file.

Hints:

> Is there a way to get the source of the program?

This time we got Java class file. We can decompile it using JD GUI available [here](http://jd.benow.ca/).
We could simply call the get_flag method, but we can also write PHP [script](decode.php).
```
>php decode.php
flag_{pretty_cool_huh}
```

The flag is `flag_{pretty_cool_huh}`.