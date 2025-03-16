#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    int numero;
    int nord;
    int sud;
    int est;
    int ouest;
    char contenu[100];
} Salle;

Salle labyrinthe[5];

void initialiserLabyrinthe() {
    labyrinthe[0].numero = 0;
    labyrinthe[0].nord = -1;
    labyrinthe[0].sud = 1;
    labyrinthe[0].est = -1;
    labyrinthe[0].ouest = -1;
    strcpy(labyrinthe[0].contenu, "Vous etes dans la salle 0.");

    labyrinthe[1].numero = 1;
    labyrinthe[1].nord = 0;
    labyrinthe[1].sud = -1;
    labyrinthe[1].est = 2;
    labyrinthe[1].ouest = -1;
    strcpy(labyrinthe[1].contenu, "Vous etes dans la salle 1. Il y a une cle dans cette salle.");

    labyrinthe[2].numero = 2;
    labyrinthe[2].nord = -1;
    labyrinthe[2].sud = -1;
    labyrinthe[2].est = 3; 
    labyrinthe[2].ouest = 1;
    strcpy(labyrinthe[2].contenu, "Vous etes dans la salle 2. Il y a une epee ici.");

    labyrinthe[3].numero = 3;
    labyrinthe[3].nord = 4;
    labyrinthe[3].sud = -1;
    labyrinthe[3].est = -1;
    labyrinthe[3].ouest = 2;
    strcpy(labyrinthe[3].contenu, "Vous etes dans la salle 3.");

    labyrinthe[4].numero = 4;
    labyrinthe[4].nord = 0;
    labyrinthe[4].sud = 3; 
    labyrinthe[4].est = 0; 
    labyrinthe[4].ouest = -1; 
    strcpy(labyrinthe[4].contenu, "Vous etes dans la salle 4. Vous avez trouve Azatoth !");
}

void afficherRegles() {
    printf("\nREGLES :\n");
    printf("1. Chercher des objets dans les salles.\n");
    printf("2. Trouver Azatoth\n");
}

void deplacer(char direction, int *position) {
    int salleActuelle = *position;
    switch (direction) {
        case 'n':
            if (labyrinthe[salleActuelle].nord != -1) {
                *position = labyrinthe[salleActuelle].nord;
            } else {
                printf("Il n'y a pas de porte vers le nord.\n");
            }
            break;
        case 's':
            if (labyrinthe[salleActuelle].sud != -1) {
                *position = labyrinthe[salleActuelle].sud;
            } else {
                printf("Il n'y a pas de porte vers le sud.\n");
            }
            break;
        case 'e':
            if (labyrinthe[salleActuelle].est != -1) {
                *position = labyrinthe[salleActuelle].est;
            } else {
                printf("Il n'y a pas de porte vers l'est.\n");
            }
            break;
        case 'o':
            if (labyrinthe[salleActuelle].ouest != -1) {
                *position = labyrinthe[salleActuelle].ouest;
            } else {
                printf("Il n'y a pas de porte vers l'ouest.\n");
            }
            break;
        default:
            printf("Direction non reconnue.\n");
    }
}

int main() {
    int position = 0;
    char commande;

    initialiserLabyrinthe();

    while (1) {
        printf("%s\n", labyrinthe[position].contenu);
        
        afficherRegles();
        
        printf("Directions possibles : ");
        if (labyrinthe[position].nord != -1) {
            printf("n ");
        }
        if (labyrinthe[position].sud != -1) {
            printf("s ");
        }
        if (labyrinthe[position].est != -1) {
            printf("e ");
        }
        if (labyrinthe[position].ouest != -1) {
            printf("o ");
        }
        printf("\nEntrez une direction (n/s/e/o) ou q pour quitter : ");
        scanf(" %c", &commande);

        if (commande == 'q') {
            break;
        }

        deplacer(commande, &position);
    }

    printf("Bravo ! Vous avez exploré le labyrinthe et récupéré tous les objets.\n");
    printf("Merci d'avoir joué !\n");

    return 0;
}
