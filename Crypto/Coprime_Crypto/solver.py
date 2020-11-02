enc = "c1ys{4_C0_ky_}_hhaFrnn75ar5!y7p3T8aep1p"

x = 38
print(enc[x],end="")
diff = 14
for i in range(len(enc)-1):
	p = x-diff
	if p < 0: p += len(enc)
	#print(p)
	print(enc[p],end="")
	x = p
print()
