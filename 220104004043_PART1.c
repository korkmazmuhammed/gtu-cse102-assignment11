#include <stdio.h>
#define N 5

int numPathsHome(int street, int avenue)
{
    int x = 1, y = 1;               /*dispatch center coordiantes*/
    if (street == x && avenue == y) /*if given coordinates equal to the dispatch then result will be zero */
        return 0;
    else if (street == x || avenue == y) /*if any coordinates equal then we can arrive by this way*/
        return 1;
    else if (street < x || avenue < y) /*avoid from walls*/
        return 0;
    return (numPathsHome(street - 1, avenue) + numPathsHome(street, avenue - 1)); /*two possible for any way*/
}

int main()
{
    int avenue, street, path;
    printf("\nEnter the street number\nstreet: ");
    scanf("%d", &street);
    printf("Enter the avenue number\navenue: ");
    scanf("%d", &avenue);
    if (street > N || avenue > N)
        printf("INVALID VALUES TRY AGAIN\n");
    else
    {
        path = numPathsHome(street, avenue);
        printf("Number of optimal path to take back home: %d\n\n", path);
    }
    return 0;
}
