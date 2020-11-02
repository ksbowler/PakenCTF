import string
import subprocess
from subprocess import PIPE

f = open("encoded")
a = f.readline().strip()
print(a)

flag = "pakenCTF"
#with subprocess.Popen('./blackboxX', shell=True, stdin=PIPE, stdout=PIPE, stderr=PIPE,universal_newlines=True) as pipe:
while True:
	for stt in string.printable:
		ff = True
		with subprocess.Popen('./blackboxX', shell=True, stdin=PIPE, stdout=PIPE, stderr=PIPE,universal_newlines=True) as pipe:
			#print(type(stt))
			out, err = pipe.communicate(flag+stt)
			#print(out[15:])
			#print(a[:54])
			if out[15:].strip() in a:
				ff = False
				print(stt)
				flag += stt
				break
	if ff:
		print("Not found")
		break
	if out[15:].strip() == a:
		print(flag)
		break
