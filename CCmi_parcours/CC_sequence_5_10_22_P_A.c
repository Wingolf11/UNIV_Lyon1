#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX 12  // Nombre de paires à stocker

int saisie_paire()
{
    int nb;

    do
    {
        printf("Enter an even number superior to 2: ");
        scanf("%d", &nb);
    } while (nb <= 2 || nb % 2 != 0);
    return nb;
}

bool est_premier(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void    goldbach(int nb, int* n1, int* n2)
{
    int i;

    for (int i = 2; i <= nb / 2; ++i) 
    {
        if (est_premier(i) && est_premier(nb - i)) 
        {
            *n1 = i;
            *n2 = nb - i;
            //printf("%d est la somme de %d et %d (tous deux premiers).\n", nb, i, nb - i);
            return; // On s'arrête à la première paire trouvée
        }
    }
}

void tab_goldbach(int T[2][MAX], int nb)
{
    int i;
    int n1;
    int n2;
    int index;

    i = 0;
    index = 0;
    while (i < nb)
    {
        goldbach(2 * i + 4, &n1, &n2);
        T[0][index] = n1;
        T[1][index] = n2;
        index++;
        i++;
    }
    
}

void affiche_tab(int T[2][MAX], int tailleT) 
{
    printf("Decompositions de Goldbach :\n");
    for (int i = 0; i < tailleT; i++) 
    {
        int nb = 2 * (i + 2);
        printf("%d = %d + %d\n", nb, T[0][i], T[1][i]);
    }
}

int main() 
{
    int nb;
    int n1;
    int n2;
    int goldbach_tab[2][MAX];

    nb = saisie_paire();
    goldbach(nb, &n1, &n2);

    nb= nb / 2 - 1; // nombre de pairs

    tab_goldbach(goldbach_tab, nb);
    affiche_tab(goldbach_tab, nb);    
    return 0;
}