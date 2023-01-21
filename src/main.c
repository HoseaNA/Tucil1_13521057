#include <stdio.h>
#include <possibilities.h>

int main()
{
    char allOps[64][3];
    int Nums[24][4];

    int numbers[4] = {1, 2, 3, 4};
    allNums(Nums, numbers);
    for (int i = 0; i < 4; i++)
    {
        printf("%d", Nums[0][i]);
    }
}