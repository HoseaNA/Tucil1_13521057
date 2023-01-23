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

void Nums(float allNums[24][4], float numbers[4])
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
                        allNums[cnt][0] = numbers[i];
                        allNums[cnt][1] = numbers[j];
                        allNums[cnt][2] = numbers[k];
                        allNums[cnt][3] = numbers[l];
                        cnt++;
                    }
                }
            }
        }
    }
}