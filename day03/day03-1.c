#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LENGTH_MAX 10
#define compare(number, repetition) for (int i = 0 ; i < length ; i++) \
                                    { \
                                        if (number[i] == '0') \
                                        { \
                                            repetition[i] -= 1; \
                                        } \
                                        else \
                                        { \
                                            repetition[i] += 1; \
                                        } \
                                    }

int main()
{
    FILE *file = fopen("day03.txt", "r");

    if (file)
    {
        char number[LENGTH_MAX] = "";
        fscanf(file, "%s", number);

        // Détermination de la longueur des représentations binaires
        int length = 0;
        while (number[length])
        {
            length++;
        }

        // repetition[i] > 0 si bit 1 plus répété, < 0 si bit 0 plus répété
        int repetition[length], gamma[length], epsilon[length];
        int gammaRate = 0, epsilonRate = 0;
        for (int i = 0 ; i < length ; i++)
        {
            repetition[i] = gamma[i] = epsilon[i] = 0;
        }
        compare(number, repetition)
        
        while (fscanf(file, "%s", number) != EOF)
        {
            compare(number, repetition)
        }

        for (int i = 0 ; i < length ; i++)
            {
                if (repetition[i] > 0)
                {
                    gamma[i] = 1;
                    epsilon[i] = 0;
                }
                else
                {
                    gamma[i] = 0;
                    epsilon[i] = 1;
                }
            }

        for (int i = 0 ; i < length ; i++)
        {
            gammaRate = gammaRate + (int) pow(2, i) * gamma[length - 1 - i];
            epsilonRate = epsilonRate + (int) pow(2, i) * epsilon[length - 1 - i];
        }
        printf("gammaRate = %d\n", gammaRate);
        printf("epsilonRate = %d\n", epsilonRate);
        printf("gammaRate * epsilonRate = %d", gammaRate * epsilonRate);
    }
    else
    {
        printf("Impossible to open the file day03.txt");
    }

    return 0;
}