#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 52

typedef struct
{
    const char *face;
    const char *suit;
} cards;

void initialize(cards deck[])
{
    int i;
    char arr[13][7] = {{"Ace"}, {"Deuce"}, {"Three"}, {"Four"}, {"Five"}, {"Six"}, {"Seven"}, {"Eight"}, {"Nine"}, {"Ten"}, {"Jack"}, {"Queen"}, {"King"}};
    int j = 0;
    for (i = 0; i < SIZE; i++)
    {
        if (i < SIZE / 4 * 1)
        {
            strcpy((char *)deck[i].suit, "Hearts");
            strcpy((char *)deck[i].face, arr[j++]);
            if (j == SIZE / 4)
                j = 0;
        }
        else if (i < SIZE / 4 * 2)
        {

            strcpy((char *)deck[i].suit, "Diamonds");
            strcpy((char *)deck[i].face, arr[j++]);
            if (j == SIZE / 4)
                j = 0;
        }
        else if (i < SIZE / 4 * 3)
        {
            strcpy((char *)deck[i].suit, "Clubs");
            strcpy((char *)deck[i].face, arr[j++]);
            if (j == SIZE / 4)
                j = 0;
        }
        else
        {
            strcpy((char *)deck[i].suit, "Spades");
            strcpy((char *)deck[i].face, arr[j++]);
        }
    }
}
void decks(cards deck[])
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("%s", deck[i].suit);
        printf(" of ");
        printf("%-7s\t\t", deck[i].face);
        if (i % 2 == 1)
            printf("\n");
    }
}
void allocation(cards deck[])
{
    int i = 0;
    for (i = 0; i < SIZE; i++)
    {
        deck[i].face = (const char *)calloc(sizeof(const char), 6);
        deck[i].suit = (const char *)calloc(sizeof(const char), 9);
    }
}
void freeAlloc(cards deck[])
{
    int i = 0;
    for (i = 0; i < SIZE; i++)
    {
        free((char *)deck[i].face);
        free((char *)deck[i].suit);
    }
}
void shuffle(cards deck[])
{

    char *str1 = (char *)calloc(sizeof(char), 6);
    char *str2 = (char *)calloc(sizeof(char), 9);
    int i, j;
    int randNum;

    for (i = 0; i < SIZE / 2; i++)
    {
        for (j = 0; j < 3; j++)
            randNum = rand() % 52;
        if (i != randNum)
        {
            strcpy(str1, (char *)deck[i].face);
            strcpy((char *)deck[i].face, (char *)deck[randNum].face);
            strcpy((char *)deck[randNum].face, str1);

            strcpy(str2, (char *)deck[i].suit);
            strcpy((char *)deck[i].suit, (char *)deck[randNum].suit);
            strcpy((char *)deck[randNum].suit, str2);
        }
    }
}
int main()
{
    cards deck[52];
    allocation(deck);
    initialize(deck);
    srand(time(NULL));
    shuffle(deck);
    decks(deck);
    freeAlloc(deck);
}