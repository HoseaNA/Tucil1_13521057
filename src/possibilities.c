#include "possibilities.h"

bool validateNum(char num)
{
    if (num != 'A' || num != '2' || num != '3' || num != '4' || num != '5' || num != '6' || num != '7' || num != '8' || num != '9' || num != '10' || num != 'J' || num != 'Q' || num != 'K')
    {
        return false;
    }
    else
    {
        return true;
    } 
}

void Ops(char allOps[64][3])
{
    char ops[4] = {'+', '-', '*', '/'};
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                allOps[cnt][0] = ops[i];
                allOps[cnt][1] = ops[j];
                allOps[cnt][2] = ops[k];
                cnt++;
            }
        }
    }
}

void Nums(float allNums[24][4], float nums[4])
{
    int i, j, k, l, cnt = 0;
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