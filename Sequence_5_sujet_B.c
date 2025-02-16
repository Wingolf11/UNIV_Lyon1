#include <stdio.h>
#include <stdlib.h>

void factoriel(int nb)
{
    int i;
    int f;

    i = 1;
    f = nb;

    if (nb == 1)
        printf("Fact = %d\n", nb);
    while (i < nb)
    {
        f = f * i;
        i++;
/*      printf("fact = %d\n", f); */
    } 
    printf("Fact = %d\n", f);
}

int somme_chiffres_pairs(int n) {  
    int add;
    int number;

    add = 0;
    while (n != 0) 
    {  
        number = n % 10;  // Extract last digit
        if (number % 2 == 0)  // Check if digit is even
            add += number;   
        n /= 10;  // Remove last digit
    } 
    return add;  // Return sum of even digits
}

int main()
{
    int nb;
    int add_pairs;

    printf("Enter a positive number between 1 and 12: ");
    scanf("%d", &nb);
    (nb < 1 || nb > 12) ? printf("Invalid input!\n") : factoriel(nb);
    add_pairs = somme_chiffres_pairs(nb);
    printf("Somme des chiffres paires = %d\n", add_pairs);
    return 0;
}

/* empty input ends in infinite loop at scanf...
Using fgets() + sscanf() for Safer Input Handling */