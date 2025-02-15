#include <stdio.h>
#include <stdlib.h>

void interval (int  val)
{
    do
    {
    printf("Enter value: ");
    if (scanf("%d", &val) != 1)
        {
            printf("not valid");
            break;
        }
    printf("%d\n", val);
    }while (val < -100 || val > 100);    
}

void    echange(int x, int  y)
{
    int sign = x * y;
    int tmp;
    if (sign >= 0)
    {
        tmp = x;
        x = y;
        y = tmp;
    }
    else
    {
        tmp = x;
        x = x + y;
        y = tmp * y;
    }
    printf("La valeur de x: %d\n", x);
    printf("La valeur de y: %d", y);
}

int main(int argc, char** argv)
{
    int val;

    int x;
    int y;

    x = atoi(argv[1]);
    y = atoi(argv[2]);

    if (!x || !y)
        return(0);
    interval(val);
    echange(x, y);
    return (0);
}