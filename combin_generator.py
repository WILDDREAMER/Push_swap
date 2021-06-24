# Python program to print all
# the possible combinations

def comb(L):
	
	for i in range(5):
		for j in range(5):
			for k in range(5):
				for l in range(5):
					for m in range(5):
				
						# check if the indexes are not
						# same
						if (i!=j and i!=k and i!=l and i!=m and j!=k and j!=l and j!=m and k!=l and k!=m and l!=m):
							print(str(L[i]) + " " + str(L[j]) +" " +  str(L[k]) +" " +  str(L[l]) +" " +  str(L[m]) )
					
# Driver Code
comb([1, 2, 3, 4, 5])
