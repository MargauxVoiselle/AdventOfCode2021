#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH_MAX 10

int main()
{
    FILE *file = fopen("day02.txt", "r");

    if (file)
    {
        long aim = 0, forward = 0, depth = 0, number = 0;
        char movement[LENGTH_MAX] = "";
    
        while (fscanf(file, "%s %ld", movement, &number) != EOF)
        {
            if (strcmp(movement, "down") == 0)
            {
                aim = aim + number;
            }
            else if (strcmp(movement, "up") == 0)
            {
                aim = aim - number;
            }
            else
            {
                forward = forward + number;
                depth = depth + aim * number;
            }
        }

        printf("The movements forward and depth equal %ld and %ld\n", forward, depth);
        printf("%ld", forward*depth);
    }
    else
    {
        printf("Impossible to open the file day02.txt");
    }
}