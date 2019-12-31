#!/usr/bin/env python2
import json
import collections
from pwn import *
r = remote("2018shell.picoctf.com",10493)
data = json.loads(open("incidents.json","r").read())

# 1st question
src_ip = collections.Counter([item["src_ip"] for item in data["tickets"]])
r.sendline(src_ip.most_common(1)[0][0])

# 2nd question
r.recvuntil("How many unique destination IP addresses were targeted by the source IP address")
requested_src_ip = r.recvuntil("?")[:-1].strip()
unique_targets = len(set([item["dst_ip"] for item in data["tickets"] if item["src_ip"] == requested_src_ip]))
r.sendline("%d"%unique_targets)

# 3rd question
files = {}
for item in data["tickets"]:
	if item["file_hash"] not in files:
		files[item["file_hash"]] = set()
	files[item["file_hash"]].add(item["dst_ip"])
ips = sum([len(v) for k,v in files.iteritems()])
r.sendline("%.2f"%(float(ips)/len(files)))
print(r.recvall())