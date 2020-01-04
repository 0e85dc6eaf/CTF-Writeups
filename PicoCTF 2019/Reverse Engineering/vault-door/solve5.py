#!/usr/bin/env python3
from urllib.parse import unquote
from base64 import b64decode
expected = expected = "JTYzJTMwJTZlJTc2JTMzJTcyJTc0JTMxJTZlJTY3JTVmJTY2JTcyJTMwJTZkJTVmJTYyJTYxJTM1JTY1JTVmJTM2JTM0JTVmJTMxJTMxJTM3JTM3JTY2JTM3JTM4JTMz"
print(unquote(b64decode(expected).decode('utf-8')))