#!/usr/bin/env python3
def calc(x):
	if x in results:
		return results[x]
	results[x] = (calc(x-1) - calc(x-2) + calc(x-3) - calc(x-4) + calc(x-5)*4660)%2**32
	return results[x]
results = {}
for i in range(5):
	results[i] = i**2+9029
for i in range(5,100022):
	results[i] = calc(i)
print(results[100021])