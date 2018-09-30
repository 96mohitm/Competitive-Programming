while (1):
	try:
		n=int(input())
		if n<2:
			print(n)
		else:
			print(2*(n-1))
	except:
		break