#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 100
#define LINES 500
#define SIZE 1000
// matrice qui va contenir les coordonnées
int coord[LINES][4] = {0};
// matrice qui va contenir les chevauchements
int diagram[SIZE][SIZE] = {0};

void parse()
{
    FILE *file = fopen("day05.txt", "r");
    char line[LENGTH];
    int i = 0;

    // récupération des coordonnées initiales et finales dans une matrice
    while (fgets(line, LENGTH, file))
    {
        sscanf(line, "%d,%d -> %d,%d", &coord[i][0], &coord[i][1], &coord[i][2], &coord[i][3]);
        i++;
    }
}

// incrémente de 1 la case correspondante dans le diagramme final
void fill(int y, int x)
{
    diagram[y][x]++;
}

// renvoie le nombre de chevauchement dans le diagramme
int overlap()
{
    int result = 0;
    for (int line = 0 ; line < SIZE ; line++)
    {
        for (int col = 0 ; col < SIZE ; col++)
        {
            if (diagram[line][col] > 1)
            {
                result++;
            }
        }
    }
    return result;
}

int main()
{
    parse();
    int x_d, y_d, x, y, x1, y1, x2, y2;
    for (int line = 0 ; line < LINES ; line++)
    {
        x1 = coord[line][0];
        x2 = coord[line][2];
        y1 = coord[line][1];
        y2 = coord[line][3];
        // dans le cas d'un déplacement selon y
        if (x1 == x2)
        {
            if (y1 > y2)
            {
                for (int y = y2 ; y <= y1 ; y++)
                {
                    fill(y, x1);
                }
            }
            else if (y1 < y2)
            {
                for (int y = y1 ; y <= y2 ; y++)
                {
                    fill(y, x1);
                }
            }
        }
        // dans le cas d'un déplacement selon x
        else if (y1 == y2)
        {
            if (x1 > x2)
            {
                for (int x = x2 ; x <= x1 ; x++)
                {
                    fill(y1, x);
                }
            }
            else if (x1 < x2)
            {
                for (int x = x1 ; x <= x2 ; x++)
                {
                    fill(y1, x);
                }
            }
        }
        // dans le cas d'un déplacement diagonal
        else
        {
            if (x1 < x2)
            {
                x_d = 1;
            }
            else if (x1 > x2)
            {
                x_d = -1;
            }
            else
            {
                x_d = 0;
            }
            if (y1 < y2)
            {
                y_d = 1;
            }
            else if (y1 > y2)
            {
                y_d = -1;
            }
            else
            {
                y_d = 0;
            }
            x = x1;
            y = y1;
            while ((x != x2 + x_d) && (y != y2 + y_d))
            {
                fill(y, x);
                x += x_d;
                y += y_d;
            }
        }
    }
    int result = overlap();
    printf("Il y a %d chevauchements", result);

    return 0;
}