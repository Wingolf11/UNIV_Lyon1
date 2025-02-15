#include <stdio.h>
#include <math.h>
#include <ctype.h>

float   saisie_non_nule()
{
    float   nb;

    do
    {
        printf("Enter a number: ");
        
        if (scanf("%f", &nb) != 1)
        {
            printf("Values are not valid!\n");
            while (getchar() != '\n');  // Clear input buffer
            continue;
        }
        
    }while (nb == 0);
    return (nb);
}

int permute(float x, float y)
{
    float   tmp;

    if (!x || !y)
        return (1);
    if (x * y < 0)
    {
        tmp = x;
        x = y;
        y = tmp;
    }
    else
    {
        tmp = x;
        x = fabs(tmp - y);
        y = tmp / y;
    }
    printf("Valeur de x: %.2f\n", x);
    printf("Valeur de y: %.2f\n", y);
    return (0);
}

int main()
{
    int check;
    float   nb;
    float   x;
    float   y;

    nb = saisie_non_nule();
    x = saisie_non_nule();
    y = saisie_non_nule();
    if (check = permute(x, y) == 1)
    {
        printf("Values not valid");
        return (0);
    }    
    return (1);
}