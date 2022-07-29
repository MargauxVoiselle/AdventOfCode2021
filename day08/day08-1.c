#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 8
// tableau qui comptera le nombre d'apparition des chiffres allant de 0 à 9
int counter[10] = {0};

#define LEN(number, length) length = 0; \
                    while (number[length] != '\0') \
                    { \
                    length++; \
                    }

void solve()
{
    FILE *file = fopen("day08.txt", "r");
    char word[LENGTH] = "";
    int position = 0, length;

    while (fscanf(file, "%s", word) == 1)
    {
        if (position > 10) // dans la partie des outputs, à droite du |
        {
            LEN(word, length)
            if (length == 2)
            {
                counter[1]++;
            }
            else if (length == 4)
            {
                counter[4]++;
            }
            else if (length == 3)
            {
                counter[3]++;
            }
            else if (length == 7)
            {
                counter[7]++;
            }
        }
        if (position == 14) // on arrive au bout de la ligne donc on en change
        {
            position = 0;
        }
        else
        {
            position++;
        }
    }
}

int main()
{
    solve();
    printf("Il y a %d apparitions", counter[1] + counter[4] + counter[7] + counter[3]);

    return 0;
}