def gcd(a,b):
	if b==0:
		return a
	else:
		return gcd(b,a%b)

t = int(input())
while t:
	a,b = input().split()
	print(gcd(int(b),int(a)))
	t=t-1