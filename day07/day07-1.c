#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 10000
int positions[1000] = {0};
// valeurs arbitraires pour le min et le max
long min = 9999, max = 0, count = 0;

void parse()
{
    FILE *file = fopen("day07.txt", "r");
    char *line = malloc(LENGTH * sizeof(char)), *number;
    fgets(line, LENGTH, file);
    int i = 0;
    while ((number = strsep(&line, ",")) != NULL)
    {
        positions[i] = atoi(number);
        if (atoi(number) > max)
        {
            max = atoi(number);
        }
        if (atoi(number) < min)
        {
            min = atoi(number);
        }
        i++;
        count++;
    }
}

void fill(long *fuel)
{
    int i, j = 0;
    // on va tester toutes les solutions, soit entre le min et le max
    for (int goal = min ; goal <= max ; goal++)
    {
        i = 0;
        // on parcourt tous les éléments
        while (i < count)
        {
            fuel[j] += abs(positions[i] - goal);
            i++;
        }
        j++;
    }
}

long minFuel(long *fuel)
{
    long min = fuel[0];
    for (int i = 1 ; i < count ; i++)
    {
        if (fuel[i] < min)
        {
            min = fuel[i];
        }
    }
    return min;
}

int main()
{
    parse();
    // tableau servant à noter le fuel nécessaire
    long *fuel = malloc(count * sizeof(long)), min;
    fill(fuel);
    min = minFuel(fuel);
    printf("Le minimum de fuel est %ld", min);

    return 0;
}