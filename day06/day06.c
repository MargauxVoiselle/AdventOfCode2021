#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 10000
#define DAY 256
unsigned long int fish[9] = {0};
unsigned long int count = 0;

void parse()
{
    FILE *file = fopen("day06.txt", "r");
    char *line = malloc(LENGTH * sizeof(char)), *number;
    fgets(line, LENGTH, file);

    while((number = strsep(&line, ",")) != NULL)
    {
        fish[atoi(number)]++;
        count++;
    }
}

int main()
{
    parse();
    unsigned long int newFish = 0;
    for (int i = 0 ; i < DAY ; i++)
    {
        newFish = fish[0];
        fish[0] = fish[1];
        fish[1] = fish[2];
        fish[2] = fish[3];
        fish[3] = fish[4];
        fish[4] = fish[5];
        fish[5] = fish[6];
        fish[6] = fish[7] + newFish;
        fish[7] = fish[8];
        fish[8] = newFish;
        count += newFish;
    }
    printf("Il y a %lu poissons à la fin", count);

    return 0;
}