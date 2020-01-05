# Forky

> In this program, identify the last integer value that is passed as parameter to the function doNothing()

The application `mmap`s shared memory and writes the values `0x3B9ACA00` to it. Then it calls `fork` 4 times, increments the value in shared memory by `0x499602D2` and calls `doNothing` function.

Since every `fork` duplicates current program, `doNothing` will be called 16 times and the final value in shared memory (passed to this function) will be equal `0x3B9ACA00 + 16*0x499602D2`.

```python
import ctypes
ctypes.c_int32(0x3B9ACA00 + 16*0x499602D2)
c_int(-721750240)
```

Flag: `picoCTF{-721750240}`