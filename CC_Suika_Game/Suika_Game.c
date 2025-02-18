#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXCERCLES 30

int val_alea() 
{
    int a = 20, b = 40;
    int random_number = a + rand() % (b - a + 1);
    
    printf("Nombre entre %d et %d : %d\n", a, b, random_number);
    return random_number;
}

//commencer à partir de la question 3; look up structures
