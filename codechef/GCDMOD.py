def fastexpomod(a,p,m):
	r = 1
	a = a%m
	while p>0 :
		if p&1 == 1 :
			r = (r*a)%m
		p = p>>1;
		a = (a*a)%m;
 
	return r;
 
def gcd(a,b):
	while b:
		a,b=b,a%b
	return a
 
 
m = 1000000007
 
t = int(input())
 
while t>0 :
	t = t-1
	# a =int(input())
	# b =int(input())
	# n =int(input())
	a, b, n = map(int, input().split())
	z = int(a-b)
	r=0
	if z==0:
		r1 = fastexpomod(a,n,m)
		r2 = fastexpomod(a,n,m)
		r = (r1+r2)
		r = r%m
	else :
		r1 = fastexpomod(a,n,z)
		r2 = fastexpomod(b,n,z)
		# r=0
		r = r1+r2
		# print(r)
		r = r%z
		r = gcd(z,r)
		# print(type(r))
		# print(type(m))
		r = r % m
	print(r) 
