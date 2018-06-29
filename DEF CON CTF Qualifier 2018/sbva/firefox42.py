#!/usr/bin/env python3
import requests
headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:42.0) Gecko/20100101 Firefox/42.0'}
r = requests.post('http://0da57cd5.quals2018.oooverflow.io/login.php',{'username':'admin@oooverflow.io','password':'admin'},headers=headers)
print(r.text)