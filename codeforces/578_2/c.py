import math

def lcm(a,b):
	return (a*b)/int(math.gcd(a,b))

temp = input().split()
n = int(temp[0])
m = int(temp[1])
q = int(temp[2])

b = lcm(int(lcm(n,m)//n), int(lcm(n,m)//m))
pa = lcm(n,m)/n
pb = lcm(n,m)/m

for i in range(q):
	qs = input().split()
	sx = int(qs[0])
	sy = int(qs[1]) - 1
	ex = int(qs[2])
	ey = int(qs[3]) - 1
	if sx == 1:
		gx = (pa*sy)//b
	else:
		gx = (pb*sy)//b
	if ex == 1:
		gy = (pa*ey)//b
	else:
		gy = (pb*ey)//b
	if gx == gy:
		print("YES")
	else:
		print("NO")
