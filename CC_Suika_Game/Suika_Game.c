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
void afficher_cercle(cercle c) 
{
    printf("Cercle : Centre (%d, %d), Rayon %d\n", c.xc, c.yc, c.r);
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