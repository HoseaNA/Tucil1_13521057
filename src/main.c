#include <stdio.h>
#include "possibilities.h"
#include "converter.h"

int main()
{
    float numbers[4];
    char input[4];
    printf("Masukkan 4 angka atau huruf :\n(A, 2-10, J, Q, K)\n");
    
    scanf("%c %c %c %c", input, input+1, input+2, input+3);
    while (!validateNum(input[0]) || !validateNum(input[1]) || !validateNum(input[2]) || !validateNum(input[3]))
    {
        printf("Input invalid, silahkan masukkan kembali input yang sesuai\n");
        scanf("%c %c %c %c", input, input+1, input+2, input+3);
    }
    numbers[0] = convertToNum(input[0]);
    numbers[1] = convertToNum(input[1]);
    numbers[2] = convertToNum(input[2]);
    numbers[3] = convertToNum(input[3]);

    char allOps[64][3];
    float NumCombs[24][4];
    
    Nums(NumCombs, numbers);
    Ops(allOps);

    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%.2f ", NumCombs[i][j]);
        }
        printf("\n");
    }
}