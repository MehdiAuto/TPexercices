import random

def afficher_menu():
    print("\n=== Jeu de Devinette de Nombre ===")
    print("1. Jouer")
    print("2. Quitter")

def jouer():
    nombre_secret = random.randint(1, 100)  
    tentatives = 0

    print("J'ai choisi un nombre entre 1 et 100. Essaie de deviner !")

    while True:
        try:
            guess = int(input("Entrez votre devinette : "))
            tentatives += 1

            if guess < nombre_secret:
                print("Trop bas ! Essaie encore.")
            elif guess > nombre_secret:
                print("Trop haut ! Essaie encore.")
            else:
                print(f"Bravo ! Vous avez deviné le nombre {nombre_secret} en {tentatives} tentatives.")
                break
        except ValueError:
            print("Veuillez entrer un nombre valide.")

def main():
    while True:
        afficher_menu()
        choix = input("Choisissez une option : ")

        if choix == '1':
            jouer()
        elif choix == '2':
            print("Merci d'avoir joué ! Au revoir !")
            break
        else:
            print("Option invalide, veuillez réessayer.")

if __name__ == "__main__":
    main()
