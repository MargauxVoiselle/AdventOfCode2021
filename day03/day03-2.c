#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LENGTH_MAX 100
#define compare(number, repetition, i) if (number[i] == '0') \
                                    { \
                                        repetition[i] -= 1; \
                                    } \
                                    else \
                                    { \
                                        repetition[i] += 1; \
                                    }

int oxygen();
int dioxydeCarbon();

int main()
{
    int oxy = 0, dio = 0;
    oxy = oxygen();
    dio = dioxydeCarbon();
    printf("oxy : %d and dio : %d\n", oxy, dio);
    printf("oxy * dio = %d", oxy * dio);

    return 0;
}

int oxygen()
{
    int count = 0, i = 0, length = 0;
    char number[LENGTH_MAX] = "", charac;
    FILE *file = fopen("day03.txt", "r"), *otherFile = NULL;
    fscanf(file, "%s", number);

    // calcul de la longueur des représentations binaires
    while (number[length])
    {
        length++;
    }

    // repetition[i] > 0 si bit 1 plus répété, < 0 si bit 0 plus répété
    int repetition[length];
    for (int j = 0 ; j < length ; j++)
    {
        repetition[j] = 0;
    }

    while (i < length && count != 1)
    {
        otherFile = fopen("result.txt", "w+");
        rewind(file); // on revient au début du fichier

        // on parcourt une première fois le fichier pour déterminer si il y a plus de 1 ou de 0 à la position souhaitée
        while (fscanf(file, "%s", number) != EOF)
        {
            compare(number, repetition, i)
        }

        // si il y a plus de bits à 1 ou autant de bits à 0 qu'à 1
        if (repetition[i] >= 0)
        {
            count = 0;
            rewind(file); // on revient au début du fichier
            // on parcourt une deuxième fois le fichier pour écrire dans l'autre fichier toutes les représentations binaires avec le 1 à la position souhaitée
            while (fscanf(file, "%s", number) != EOF)
            {
                if (number[i] == '1')
                {
                    fprintf(otherFile, "%s\n", number);
                    count++;
                }
            }
        }
        // si il y a plus de bits à 0
        else
        {
            count = 0;
            rewind(file); // on revient au début du fichier

            // on parcourt une deuxième fois le fichier pour écrire dans l'autre fichier toutes les représentations binaires avec le 0 à la position souhaitée
            while (fscanf(file, "%s", number) != EOF)
            {
                if (number[i] == '0')
                {
                    fprintf(otherFile, "%s\n", number);
                    count++;
                }
            }
        }
        i++; // on passe au bit suivant

        // copie du contenu du fichier de otherFile dans file
        fclose(file);
        file = fopen("copyResult.txt", "w+");
        rewind(otherFile);
        while (fscanf(otherFile, "%s", number) != EOF)
        {
            fprintf(file, "%s\n", number);
        }
        fclose(otherFile);
    }
    rewind(file);
    fscanf(file, "%s", number);
    printf("oxygen is %s\n", number);
    fclose(file);

    int result = 0;
    for (int k = 0 ; k < length ; k++)
        {
            if (number[length - 1 - k] == '1')
            {
                result = result + (int) pow(2, k);
            }
        }
    return result;
}

int dioxydeCarbon()
{
    int count = 0, i = 0, length = 0;
    char number[LENGTH_MAX] = "", charac;
    FILE *file = fopen("day03.txt", "r"), *otherFile = NULL;
    fscanf(file, "%s", number);

    // calcul de la longueur des représentations binaires
    while (number[length])
    {
        length++;
    }

    // repetition[i] > 0 si bit 1 plus répété, < 0 si bit 0 plus répété
    int repetition[length];
    for (int j = 0 ; j < length ; j++)
    {
        repetition[j] = 0;
    }

    while (i < length && count != 1)
    {
        otherFile = fopen("result.txt", "w+");
        rewind(file); // on revient au début du fichier

        // on parcourt une première fois le fichier pour déterminer si il y a plus de 1 ou de 0 à la position souhaitée
        while (fscanf(file, "%s", number) != EOF)
        {
            compare(number, repetition, i)
        }

        // si il y a plus de bits à 1 ou autant de bits à 0 qu'à 1
        if (repetition[i] >= 0)
        {
            count = 0;
            rewind(file); // on revient au début du fichier
            // on parcourt une deuxième fois le fichier pour écrire dans l'autre fichier toutes les représentations binaires avec le 1 à la position souhaitée
            while (fscanf(file, "%s", number) != EOF)
            {
                if (number[i] == '0')
                {
                    fprintf(otherFile, "%s\n", number);
                    count++;
                }
            }
        }
        // si il y a plus de bits à 0
        else
        {
            count = 0;
            rewind(file); // on revient au début du fichier

            // on parcourt une deuxième fois le fichier pour écrire dans l'autre fichier toutes les représentations binaires avec le 0 à la position souhaitée
            while (fscanf(file, "%s", number) != EOF)
            {
                if (number[i] == '1')
                {
                    fprintf(otherFile, "%s\n", number);
                    count++;
                }
            }
        }
        i++; // on passe au bit suivant

        // copie du contenu du fichier de otherFile dans file
        fclose(file);
        file = fopen("copyResult.txt", "w+");
        rewind(otherFile);
        while (fscanf(otherFile, "%s", number) != EOF)
        {
            fprintf(file, "%s\n", number);
        }
        fclose(otherFile);
    }
    rewind(file);
    fscanf(file, "%s", number);
    fclose(file);

    int result = 0;
    for (int k = 0 ; k < length ; k++)
        {
            if (number[length - 1 - k] == '1')
            {
                result = result + (int) pow(2, k);
            }
        }
    return result;
}