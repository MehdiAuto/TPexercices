T = [[10,5,-3,17,82],[9,0,0,8,-7],[32,20,1,0,14],[0,0,8,7,6]]
i = int(input("choisissez une ligne: "))
j = int(input("choisissez une colonne: "))

print("la valeur correspendante est : ",T[i][j])

valeur_max = T[0][0]
valeur_min = T[0][0]

for i in range(4):
	for j in range(5):
		if T[i][j] < valeur_min:
			valeur_min = T[i][j]
		if T[i][j] > valeur_max:
			valeur_max = T[i][j]
			
print("le max est : ", valeur_max)
print("le min est : ", valeur_min)
