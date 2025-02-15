#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int alea_bornee() 
{
    int min = 20, max = 40;
    int random_number = min + rand() % (max - min + 1);
    
    printf("Nombre entre %d et %d : %d\n", min, max, random_number);
    return random_number;
}

int pairs_impairs(int tirages)
{
    int pairs;
    int count;

    pairs = 0;
    count = 0;

    while (count++ < tirages)
        if (alea_bornee() % 2 == 0)
            pairs++;
    return (pairs);
}

int main ()
{
    srand(time(NULL));

    int rn;
    int odd;
    int even;
    int tirages;

    printf("Combien de tirages: \n");
    scanf("%d", &tirages);
    while (getchar() != '\n');
    printf("First question test: \n");
    rn = alea_bornee();
    printf("\nQuestion 3 et 4: \n");
    even = pairs_impairs(tirages);
    odd = abs(tirages - even);
    printf("Even = %d\n", even);
    printf("Odd = %d\n", odd);
    return 0;
}