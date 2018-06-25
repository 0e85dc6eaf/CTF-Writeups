import socket
from captcha import crack
from nearest_power import find_nearest_power
def read_until(str,s):
	data = s.recv(1024)
	print data
	t = time.time()
	while str not in data:
		tmp = s.recv(1024)
		if len(tmp) > 0:
			print tmp
		data += tmp
	return data
HOST = '37.139.22.174'
PORT = 11740
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))
data = read_until("sha256",s)
response = crack(data[-7:-1])+"\n"
s.sendall(response)
print response
for i in range(10):
	print "Round %d \n"%i
	data = read_until("submit r",s)
	for line in data.split("\n"):
		if "n = " in line:
			np = find_nearest_power(int(line[3:]))
			response = str(np)+"\n"
			s.sendall(response)
			print response
s.close()