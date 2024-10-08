x = int(input('Saisir la valeur du premier entier: '))
y = int(input('Saisir la valeur du deuxième entier: '))
z = int(input('Saisir la valeur du troisième entier: '))

a =[x,y,z]
print('Les valeurs de base :', a)

a.sort()
print("Les valeurs dans l'ordre croissant :",a)

a.sort(reverse=True)
print("Les valeurs dans l'ordre décroissant :", a)
