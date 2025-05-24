#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    char citiesServed[3];

} Hospital;
/*function that calculate the number of combinations*/
int calcCombnum(int n, int r)
{
    int counter = 0;
    int i;
    int sum = 1;
    while (counter++ < r)
        sum *= (n--);
    for (i = r; i >= 1; i--)
        sum /= i;
    return sum;
}
/*recursive function that fill the combinations array with possible combinations*/
void fillComb(int **combinations, int arr[], int data[], int start, int end, int index, int r, int *count)
{
    int j, i;
    if (index == r) /*if we finished get the results to main array*/
    {
        for (j = 0; j < r; j++)
        {
            combinations[*count][j] = data[j];
        }
        (*count)++; /*go to the next index*/
        return;
    }

    for (i = start; i <= end && end - i + 1 >= r - index; i++) /*call the function many times till last index and if the interval is right*/
    {
        data[index] = arr[i];
        fillComb(combinations, arr, data, i + 1, end, index + 1, r, count);
    }
}
/*function that operate the combinations*/
void getCombinations(int **combinations, int arr[], int n, int r, int maxCombinations)
{
    int data[r];                                              /*array that help us to catch combinations*/
    int size = 0;                                             /*as a counter to not lose the place that we stayed*/
    fillComb(combinations, arr, data, 0, n - 1, 0, r, &size); /*get the combinations*/
}

/*function that helps to check current combination is suitable or not*/
int findCity(int **combination, char locations[][4], char cities[], int fi, int combNum, int numHp)
{
    int m, j, k;
    int flag = 1;
    int size = 0;
    while (cities[size++])
        ;
    size -= 1;
    char arr[size];
    for (j = 0; j < size; j++) /*fill the array with 1*/
        arr[j] = '1';

    for (m = 0; m < numHp; m++)
    {
        for (j = 0; j < numHp; j++)
        {
            for (k = 0; k < size; k++)
            {
                if (locations[combination[fi][m]][j] == cities[k]) /*check the current combinations and if the city is found mark it*/
                    arr[k] = '0';
            }
        }
    }

    int index = 0;
    while (arr[index]) /*control after markingn and returning the result to the recursive function*/
    {
        if (arr[index++] != '0')
            flag = 0;
    }
    return flag;
}

/*function that takes first index of combinations and looks for all combinations and returning the result*/
int possibleHp(int **combination, char cities[], char locations[][4], int fi, int combNum, int numHp)
{
    if (fi == combNum) /*if we have not found till end then return -1*/
        return -1;
    else
    {
        int founder = findCity(combination, locations, cities, fi, combNum, numHp); /*get the result for current combination*/
        if (founder == 1)                                                           /*if we found then return the founded index of combinations*/
            return fi;
    }
    return possibleHp(combination, cities, locations, fi + 1, combNum, numHp);
}
/*fill the hospital struct with founded data and print it*/
void initialHp(Hospital hp[], char locations[][4], int **combinations, int index, int numHp)
{
    int i;
    for (i = 0; i < numHp; i++)
    {
        strcpy(hp[i].citiesServed, locations[combinations[index][i]]);
        hp[i].name = (char *)malloc(sizeof(char) * sizeof(locations[0]));
        strcpy(hp[i].name, locations[combinations[index][i]]);
        printf("Hospital - %d\n", i + 1);
        printf("Hospital locations - %s\n", hp[i].citiesServed);
    }
}

int main()
{
    int numHp, sizeLoc, combnum; /*variables for manipulation the data*/

    int i;
    char cities[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    char locations[5][4] = {{'A', 'C', 'D'}, {'A', 'B', 'C'}, {'B', 'F'}, {'C', 'E', 'F'}};

    sizeLoc = sizeof(locations) / sizeof(locations[0]) - 1; /*row number of locations array*/

    printf("Enter the maximum number of hospitals that can be constructed:");
    scanf("%d", &numHp);

    if (numHp > sizeLoc) /*if taken number is bigger than locations size update it to manipulate data in a right way*/
        numHp = sizeLoc;
    Hospital hp[numHp]; /*hospital struct array many as required hosipital*/

    combnum = calcCombnum(sizeLoc, numHp); /*get the number of combination C(n ,r)*/

    int **combarr; /*variable that store the combinations*/
    combarr = (int **)malloc(sizeof(int *) * combnum);
    for (i = 0; i < combnum; i++)
        combarr[i] = (int *)malloc(numHp * sizeof(int));

    int arr[sizeLoc]; /*array that help to determine the combinations*/
    for (i = 0; i < sizeLoc; i++)
        arr[i] = i;

    getCombinations(combarr, arr, sizeLoc, numHp, combnum); /*get the combinations*/

    int result = possibleHp(combarr, cities, locations, 0, combnum, numHp); /*get the result*/

    if (result != -1)
    {
        printf("\nYes, can offer health care to all!\n\n");
        initialHp(hp, locations, combarr, result, numHp); /*fill the hospital and print it*/
    }
    else
    {
        printf("\nNo,some cities are not covered!\n\n");
    }
    for (i = 0; i < combnum; i++)
    {
        free(combarr[i]);
    }
    free(combarr);
}