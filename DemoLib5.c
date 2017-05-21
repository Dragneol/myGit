#include <stdio.h>

void clear () { 
while ( getchar() != '\n' ); 
} 

int getInt(int min, int max)
{
    int value, keeptrying = 1, rc;
    char after;
    do {
        printf("Enter a whole number :\n"
                "in rage[%d,%d] : ",
                min, max);
        rc = scanf("%d%c", &value, &after);
        if (!rc)
        {
            printf("**NO input accepted**\n\n");
            clear();
        } else if (after != '\n')
        {
            printf("**Trailing character!**\n\n");
            clear();
        } else if (value < min || value > max)
        {
            printf("**Out of range**\n\n");
            clear();
        }else keeptrying = 0;
    } while (keeptrying);
    return value;
}

main()
{
    int min, max;
    scanf("%d%d", &min, &max);
    getInt(min,max);
    printf("%d is in [%d,%d]\n", getInt(min,max), min, max);
}
