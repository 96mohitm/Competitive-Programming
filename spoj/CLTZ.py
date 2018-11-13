while (1):
	try:
		n=int(input())
		# print(n)
		r=1
		while n!=1 :
			if (n%2 == 1):
				n = int((3)*n + 1 )
			else:
				n = int(n>>1)
			# n=x
			# print(n)
			r=r+1
		print(r)
	except:
		break




# (0.5 + 2.5 * (1)) * f(K-1) + (f(K-1) mod 2)