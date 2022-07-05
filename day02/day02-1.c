#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH_MAX 10

int main()
{
    FILE *file = fopen("day02.txt", "r");

    if (file)
    {
        char movement[LENGTH_MAX] = "";
        long number = 0, forward = 0, depth = 0;

        while (fscanf(file, "%s %ld", movement, &number) != EOF)
        {
            if (strcmp(movement, "forward") == 0) // forward
            {
                forward = forward + number;
            }
            else if (strcmp(movement, "down") == 0) // down
            {
                depth = depth + number;
            }
            else // up
            {
                depth = depth - number;
            }
        }
        printf("The directions forward and down equal %ld and %ld\n", forward, depth);
        printf("%ld", forward * depth);
        
        fclose(file);
    }
    else
    {
        printf("Impossible to open the file day02.txt");
    }

    return 0;
}