T=[1,0,0,0,0,0,0,0,0,0]

for j in range(10):
	for i in range(j):
		T[j] += T[i]
		
for j in range(10):
	print(T[j])
