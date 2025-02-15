#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int saisie_positive() {
    char *nb_str = NULL;
    size_t size = 0;
    char *endptr;
    long nb;

    printf("Enter a positive value: ");
    
    // Use getline() to dynamically allocate space for input
    if (getline(&nb_str, &size, stdin) == -1) {
        printf("Error reading input.\n");
        free(nb_str);
        return -1;
    }

    // Remove newline if present
    nb_str[strcspn(nb_str, "\n")] = '\0';
    if (strcmp(nb_str, "0") == 0) 
    {
        free(nb_str);
        return 0;
    }
    // Convert string to number with error checking
    nb = strtol(nb_str, &endptr, 10); // 10 is the base
    
    // Free allocated memory
    free(nb_str);

    // Check if the entire string was a valid integer
    if (*endptr != '\0' || endptr == nb_str) {
        printf("Invalid input! Please enter a valid integer.\n");
        return -1;
    }

    // Ensure the number is positive
    if (nb < 0) {
        printf("Only positive values are allowed.\n");
        return -1;
    }

    return (int)nb;  // Return the valid positive integer
}

int chiffres_pairs_impairs(int nb, int length)
{
    char *c_nb;
    int even = 0;
    int i = 0;

    // Allocate enough memory for the number + null terminator
    c_nb = (char*)malloc(length + 1);
    if (!c_nb) 
    {
        printf("Memory allocation failed\n");
        return 0;
    }

    // Convert number to string
    sprintf(c_nb, "%d", nb);

    // Loop through each character
    while (c_nb[i] != '\0') 
    {
        if (isdigit(c_nb[i])) 
        {  // Ensure we're checking only digits
            if ((c_nb[i] - '0') % 2 == 0)
                even++;
        }
        i++;
    }

    free(c_nb);
    return even;
}

int main() {
    int nb, even, odd, length;

    nb = saisie_positive();
    // in case input is 0, 0 is considered an even number.
    if (nb < 0) {
        printf("Non-valid input: enter a positive number\n");
        return 0;
    }

    length = snprintf(NULL, 0, "%d", nb);  // Get the number of digits
    printf("nb = %d\n", nb);

    even = chiffres_pairs_impairs(nb, length);
    odd = length - even;  // Corrected logic

    printf("Even = %d\n", even);
    printf("Odd = %d\n", odd);
    printf("Length = %d\n", length);

    return 0;
}

