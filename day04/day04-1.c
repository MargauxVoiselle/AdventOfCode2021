#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// matrice à 3 dimensions qui recueillera les grilles du bingo
#define BOARD_SIZE 5
#define NUMBER_BOARDS 100
int boards[NUMBER_BOARDS][BOARD_SIZE][BOARD_SIZE] = {0};

// tableau d'entiers qui contiendra les numéros du tirage
#define LENGTH 1000
int draw[LENGTH] = {0};

// récupère le tirage et les différentes grilles du bingo
void parse()
{
    FILE* file = fopen("day04.txt", "r");
    char *line = malloc(LENGTH*sizeof(char)), *number;
    
    // récupération des valeurs tirées pour le bingo (premières lignes du fichier)
    fgets(line, LENGTH, file);
    int i = 0;
    while ((number = strsep(&line, ",")) != NULL)
    {
        draw[i] = atoi(number); // conversion des chaînes en entier pour les stocker
        i++;
    }
    free(line);

    char boardLine[LENGTH] = "", *workingLine;
    // récupération des différentes grilles du bingo
    for (int index = 0 ; index < NUMBER_BOARDS ; index++)
    {
        fgets(boardLine, LENGTH, file);
        for (int line = 0 ; line < BOARD_SIZE ; line++)
        {
            fgets(boardLine, LENGTH, file);
            workingLine = boardLine;
            for (int col = 0 ; col < BOARD_SIZE ; col++)
            {
                boards[index][line][col] = strtol(workingLine, &workingLine, 10);
            }
        }
    }
}

// remplace une valeur par -1 si elle apparaît dans le tirage
void mark(int index, int value)
{
    for (int line = 0 ; line < BOARD_SIZE ; line++)
    {
        for (int col = 0 ; col < BOARD_SIZE ; col++)
        {
            if (boards[index][line][col] == value)
            {
                boards[index][line][col] = -1;
            }
        }
    }
}

// calcule la somme des termes non marqués d'une grille
int unmarkedSum(int index)
{
    int sum = 0;
    for (int line = 0 ; line < BOARD_SIZE ; line++)
    {
        for (int col = 0 ; col < BOARD_SIZE ; col++)
        {
            if (boards[index][line][col] > 0)
            {
                sum += boards[index][line][col];
            }
        }
    }
    return sum;
}

// renvoie 1 (true) si le tableau est gagnant, 0 sinon
int winOrNot(int index)
{
    int sum = 0;
    // test des sommes sur les lignes
    for (int line = 0 ; line < BOARD_SIZE ; line++)
    {
        for (int col = 0 ; col < BOARD_SIZE ; col++)
        {
            sum += boards[index][line][col];
        }
        if (sum == -5)
        {
            return 1; // le tableau est gagnant
        }
        sum = 0;
    }

    // test des sommes sur les colonnes
    for (int col = 0 ; col < BOARD_SIZE ; col++)
    {
        for (int line = 0 ; line < BOARD_SIZE ; line++)
        {
            sum += boards[index][line][col];
        }
        if (sum == -5)
        {
            return 1; // le tableau est gagnant
        }
        sum = 0;
    }
    return 0;
}

int main()
{
    parse();
    int winnerBoard = 0, winner = 0, i = 0, numBoard, lastNumber = 0, sumUnmarked = 0;
    // tant qu'on a pas trouvé un tableau gagnant
    while (!(winner))
    {
        numBoard = 0;
        // pour toutes les grilles
        while (numBoard < NUMBER_BOARDS)
        {
            mark(numBoard, draw[i]); // on marque le numéro tiré sur la grille
            // si on a trouvé le tableau gagnant
            if (winOrNot(numBoard))
            {
                lastNumber = draw[i]; // on repère le dernier numéro tiré
                sumUnmarked = unmarkedSum(numBoard); // on fait la somme des numéros non marqués
                printf("La grille gagnante est la %dème\n", numBoard + 1);
                numBoard = NUMBER_BOARDS; // permet de sortir de la première boucle
                winner = 1; // permet de sortir de la seconde boucle
            }
            numBoard++;
        }
        i++;
    }
    printf("Le dernier numéro tiré est le %d\n", lastNumber);
    printf("La somme des numéros non marqués est %d\n", sumUnmarked);
    printf("Le produit vaut alors %d", lastNumber * sumUnmarked);

    return 0;
}