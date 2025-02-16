#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int alea_bornee() 
{
    int min = 10, max = 30;
    int random_number = min + rand() % (max - min + 1);
    
    printf("Nombre entre %d et %d : %d\n", min, max, random_number);
    return random_number;
}

int petit_grand()
{
    int count;
    int over;


    count = 0;
    over = 0;
    while (count++ < 20)
    {
        if (alea_bornee() >= 20)
            over++;
    }
    return (over);
}

int main()
{
    int over;
    int under;

    srand(time(NULL));
    over = petit_grand();
    under =  abs(over - 20);
    printf("Over or equal to 20: %d\n", over);
    printf("Under 20: %d\n", under);
    return (0);
}
