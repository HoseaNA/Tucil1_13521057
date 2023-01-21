#include <stdio.h>
#include <possibilities.h>

void allOps(char **allOps)
{
    char **arrOps;
    char ops[4] = {'+', '-', '*', '/'};
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                arrOps[cnt][0] = ops[i];
                arrOps[cnt][1] = ops[j];
                arrOps[cnt][2] = ops[k];
                cnt++;
            }
        }
    }
    return arrOps;
}

void allNums(int **allNums, int *nums)
{
    int i, j, k, l, cnt;
    int **allNums;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            for (k = 0; k < 4; k++)
            {
                for (l = 0; l < 4; l++)
                {
                    if (i != j && i != k && i != l && j != k && j != l && k != l)
                    {
                        allNums[cnt][0] = nums[i];
                        allNums[cnt][1] = nums[j];
                        allNums[cnt][2] = nums[k];
                        allNums[cnt][3] = nums[l];
                        cnt++;
                    }
                }
            }
        }
    }
}