from Crypto.Util.number import *

p = pow(2, 521) - 1
g = 23465675253
x = 45466765
#m = int(input('plainText:'))
y = pow(g, x, p)
r = 35426
#enc1 = pow(g, r, p)
#enc2 = pow(y, r, p) * m % p
#print('code1:' + str(enc1))
#print('code2:' + str(enc2))
code1 = 4421664084074670090821428393252601896707238833568529471788988373423872134415886118801715014521273069823897226704004664676566665964855651716107694758506146136
code2 = 2120403903076703834514243322316105937757315062520771728791977484839802965205251266018189029958131618069233499450694892261180928293911858348401790013829165266

ic1 = inverse(code1,p)
mes = (pow(ic1,x,p)*code2)%p

print(long_to_bytes(mes))
