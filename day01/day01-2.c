#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("day01-2.txt", "r");
    long oldFirst = 0, oldSecond = 0, oldThird = 0, newFirst = 0, newSecond = 0, newThird = 0, oldSum = 0, newSum = 0;
    int count = 0;
    if (file)
    {
        fscanf(file, "%ld %ld %ld", &oldFirst, &oldSecond, &oldThird);
        while (fscanf(file, "%ld", &newThird) != EOF)
        {
            newFirst = oldSecond;
            newSecond = oldThird;
            oldSum = oldFirst + oldSecond + oldThird;
            newSum = newFirst + newSecond + newThird;
            if (newSum > oldSum)
            {
                count++;
            }
            oldFirst = newFirst;
            oldSecond = newSecond;
            oldThird = newThird;
        }
        printf("There were %d increases", count);
    }
    else
    {
        printf("Impossible to open the file day01-2.txt");
    }

    return 0;
}