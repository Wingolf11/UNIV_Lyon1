#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define MAXCERCLES 30
#define WINDOW_SIZE 500

int val_alea() 
{
    int a = 1, b = 10;
    int random_number = a + rand() % (b - a + 1);
    
    //printf("Nombre entre %d et %d : %d\n", a, b, random_number);
    return random_number;
}

typedef struct 
{
    int xc, yc; // Coordonnées du centre
    int r;      // Rayon du cercle
} cercle;

typedef struct
{
    int nb;
    cercle  tab[MAXCERCLES];

} suika;

cercle creer_cercle() 
{
    cercle c;
    int h;

    // Générer un rayon multiple de 10 entre 10 et 100
    c.r = (val_alea()) * 10;

    // Générer xc et yc en respectant la contrainte de la fenêtre
    c.xc = (val_alea() % (WINDOW_SIZE - 2 * c.r)) + c.r;
    c.yc = (val_alea() % (WINDOW_SIZE - 2 * c.r)) + c.r;
    return c;
}

// Fonction pour afficher un cercle
void afficher_cercle(int i, cercle c) 
{
    printf("Cercle %d: Centre (%d, %d), Rayon %d\n", i, c.xc, c.yc, c.r);
}

void ajouter_un_cercle(suika *s) 
{
    if (s->nb < MAXCERCLES) {
        s->tab[s->nb] = creer_cercle(); // Ajout d'un nouveau cercle
        s->nb++;
        printf("Cercle ajouté avec succès !\n");
    } else {
        printf("Erreur : tableau plein, impossible d'ajouter un cercle.\n");
    }
}

bool intersection(cercle c1, cercle c2)
{
    double D;
    double S;

    D = sqrt(pow(c2.xc - c1.xc, 2) + pow(c2.yc - c1.yc,2)); /*Distance euclidienne*/
    S = c1.r + c2.r; //somme des rayons

    return D <= S; //si D <= S alors vrai, sinon faux
}

bool premiere_intersection(suika *s, int *ic1, int *ic2)
{
    for (int i = 0; i < s->nb; i++) 
    {
        for (int j = i + 1; j < s->nb; j++) 
        {
            if (s->tab[i].r == s->tab[j].r && intersection(s->tab[i], s->tab[j])) 
            {
                *ic1 = i;
                *ic2 = j;
                return true; // Found a pair of circles that can merge
            }
        }
    }

    // No matching circles found
    *ic1 = -1;
    *ic2 = -1;
    return false;
}

void fusion(suika *s, int ic1, int ic2)
{
    if (ic1 < 0 || ic2 < 0 || ic1 >= s->nb || ic2 >= s->nb || ic1 == ic2) {
        printf("Erreur: indices invalides pour la fusion.\n");
        return;
    }

    // Calculate new position (average of both centers)
    s->tab[ic1].xc = (s->tab[ic1].xc + s->tab[ic2].xc) / 2;
    s->tab[ic1].yc = (s->tab[ic1].yc + s->tab[ic2].yc) / 2;

    // Increase the radius by 10
    s->tab[ic1].r += 10;

    // Replace ic2 with the last circle in the list
    s->tab[ic2] = s->tab[s->nb - 1];

    // Reduce the number of circles
    s->nb--;

    printf("New circle at index (%d, %d) and this radius %d.\n",
           s->tab[ic1].xc, s->tab[ic1].yc, s->tab[ic1].r);
}

//THIS ONE USES RANDOM GENERATED CIRCLES:
int main() 
{
    srand(time(NULL)); // Initialize random seed

    suika game;
    game.nb = val_alea(); // Generate 5 random circles

    for (int i = 0; i < game.nb; i++)
        game.tab[i] = creer_cercle();  // Generate and store a random circle

    // Display generated circles
    printf("Initialy generated Circles:\n");
    for (int i = 0; i < game.nb; i++)
        afficher_cercle(i, game.tab[i]);  // Print circle details

    int ic1, ic2;

    // Check if two circles can merge
    if (premiere_intersection(&game, &ic1, &ic2)) 
    {
        printf("\nFusion possible between circles at indices %d and %d.\n", ic1, ic2);
        fusion(&game, ic1, ic2);  // Merge them
    } 
    else 
        printf("\nNo circles can merge.\n");

    printf("\nCircles after fusion:\n");
    for (int i = 0; i < game.nb; i++) 
        afficher_cercle(i, game.tab[i]);  
    return 0;
}