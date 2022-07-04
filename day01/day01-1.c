#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file = NULL;
    file = fopen("day01-1.txt", "r"); // ouverture du fichier en mode lecture
    if (file) // vérification de la bonne ouverture du fichier
    {
        long new = 0, old = 0;
        int count = 0;
        fscanf(file, "%ld", &new);
        old = new;

        while (fscanf(file, "%ld", &new) != EOF)
        {
            if (new > old)
            {
                count++;
            }
            old = new;
        }

        fclose(file);
        printf("The sea level has increased %d times", count);
    }
    else
    {
        printf("Impossible to open the file day01-1.txt");
    }

    return 0;
}