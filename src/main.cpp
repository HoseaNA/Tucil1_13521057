#include <iostream>
#include <sstream>
#include <map>
#include <fstream>
#include <chrono>
#include <string>
#include <cstdlib>
#include <string.h>
using namespace std;

float count(float num1, float num2, char op)
{
    if (op == '+')
    {
        return num1 + num2;
    }
    else if (op == '-')
    {
        return num1 - num2;
    }
    else if (op == '*')
    {
        return num1 * num2;
    }
    else if (op == '/')
    {
        return num1 / num2;
    }
    else
    {
        return 1.0;
    }
}

float combination(float numbers[4], char ops[3], int comb)
{
    if (comb == 1) /*((A B) C) D*/
    {
        return count(count(count(numbers[0], numbers[1], ops[0]), numbers[2], ops[1]), numbers[3], ops[2]);
    }
    else if (comb == 2) /*(A (B C)) D*/
    {
        return count(count(numbers[0], count(numbers[1], numbers[2], ops[1]), ops[0]), numbers[3], ops[2]);
    }
    else if (comb == 3) /*A (B (C D))*/
    {
        return count(numbers[0], count(numbers[1], count(numbers[2], numbers[3], ops[2]), ops[1]), ops[0]);
    }
    else if (comb == 4) /*A ((B C) D)*/
    {
        return count(numbers[0], count(count(numbers[1], numbers[2], ops[1]), numbers[3], ops[2]), ops[0]);
    }
    else if (comb == 5) /*(A B) (C D)*/
    {
        return count(count(numbers[0], numbers[1], ops[0]), count(numbers[2], numbers[3], ops[2]), ops[1]);
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

void numsManual(float numbers[4])
{
    map<string, float> HashInput;
    HashInput["2"] = 2.0;
    HashInput["3"] = 3.0;
    HashInput["4"] = 4.0;
    HashInput["5"] = 5.0;
    HashInput["6"] = 6.0;
    HashInput["7"] = 7.0;
    HashInput["8"] = 8.0;
    HashInput["9"] = 9.0;
    HashInput["10"] = 10.0;
    HashInput["A"] = 1.0;
    HashInput["J"] = 11.0;
    HashInput["Q"] = 12.0;
    HashInput["K"] = 13.0;

    cout << "Masukkan 4 angka atau huruf :\n(A, 2-10, J, Q, K)\n";
    for (int i = 0; i < 4; i++)
    {
        string input;
        cin >> input;

        while (HashInput.find(input) == HashInput.end())
        {
            cout << "Input tidak sesuai, silahkan input perbaikan sebanyak input yang tidak sesuai\n";
            cin >> input;
        }
        numbers[i] = HashInput[input];
    }
}

void numsRandom(float numbers[])
{
    string cardList[13] = {"A",
                           "2",
                           "3",
                           "4",
                           "5",
                           "6",
                           "7",
                           "8",
                           "9",
                           "10",
                           "J",
                           "Q",
                           "K"};

    cout << "Kartu yang diperoleh :\n";
    srand(time(0));
    for (int i = 0; i < 4; i++)
    {
        int number = rand() % 13;
        cout << cardList[number] << " ";
        numbers[i] = (float)(number + 1);
    }
    cout << "\n\n";
}

void mainCounter(float numbers[4])
{
    char allOps[64][3];
    float allNums[24][4];

    auto timeStart = std::chrono::high_resolution_clock::now();

    Ops(allOps);
    Nums(allNums, numbers);

    std::stringstream solutions;
    int cntSolution = 0;
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            if (abs(combination(allNums[i], allOps[j], 1) - 24) < 0.00001) /*((A B) C) D*/
            {
                solutions << "((" << allNums[i][0] << allOps[j][0] << allNums[i][1] << ")" << allOps[j][1] << allNums[i][2] << ")" << allOps[j][2] << allNums[i][3] << endl;
                cntSolution++;
            }
            if (abs(combination(allNums[i], allOps[j], 2) - 24) < 0.00001) /*(A (B C)) D*/
            {
                solutions << "(" << allNums[i][0] << allOps[j][0] << "(" << allNums[i][1] << allOps[j][1] << allNums[i][2] << "))" << allOps[j][2] << allNums[i][3] << endl;
                cntSolution++;
            }
            if (abs(combination(allNums[i], allOps[j], 3) - 24) < 0.00001) /*A (B (C D))*/
            {
                solutions << allNums[i][0] << allOps[j][0] << "(" << allNums[i][1] << allOps[j][1] << "(" << allNums[i][2] << allOps[j][2] << allNums[i][3] << "))" << endl;
                cntSolution++;
            }
            if (abs(combination(allNums[i], allOps[j], 4) - 24) < 0.00001) /*A ((B C) D)*/
            {
                solutions << allNums[i][0] << allOps[j][0] << "((" << allNums[i][1] << allOps[j][1] << allNums[i][2] << ")" << allOps[j][2] << allNums[i][3] << ")" << endl;
                cntSolution++;
            }
            if (abs(combination(allNums[i], allOps[j], 5) - 24) < 0.00001) /*(A B) (C D)*/
            {
                solutions << "(" << allNums[i][0] << allOps[j][0] << allNums[i][1] << ")" << allOps[j][1] << "(" << allNums[i][2] << allOps[j][2] << allNums[i][3] << ")" << endl;
                cntSolution++;
            }
        }
    }
    auto timeEnd = std::chrono::high_resolution_clock::now();
    auto runTime = std::chrono::duration_cast<std::chrono::nanoseconds>(timeEnd - timeStart);

    cout << "Terdapat " << cntSolution << " solusi\n";
    cout << solutions.str() << endl;
    cout << "Runtime :" << runTime.count() * 1e-9 << " Detik\n" << endl;

    cout << "Apakah ingin disimpan dalam file?\n(y/Y untuk ya n/N untuk tidak)\n";
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        string path;
        cout << "Masukkan nama file :\n";
        cin >> path;
        ofstream file;
        file.open("./test/" + path + ".txt");
        file << "Terdapat " << cntSolution << " solusi" << endl
             << solutions.str() << endl
             << "Runtime :" << runTime.count() * 1e-9 << " Detik"<< endl;
        file.close();
        cout << "Berhasil menuliskan hasil pada file " << path << ".txt\nThank you and goodbye :)\n\n";
    }
    else if (choice == 'n' || choice == 'N')
    {
        cout << "Ok, bye >:(\n\n";
    }
}

int main()
{
    float numbers[4];
    bool running = true;
    while (running)
    {
        int choice;
        cout << "24 Game Solver with Brute Force\nBy Hosea N.A.\n\n";
        cout << "Pilih cara input\n";
        cout << "Ketik 1 untuk input manual\nKetik 2 untuk input random\nKetik 3 untuk keluar dari program\n";
        cin >> choice;
        if (choice == 1)
        {
            numsManual(numbers);
            mainCounter(numbers);
        }
        else if (choice == 2)
        {
            numsRandom(numbers);
            mainCounter(numbers);
        }
        else if (choice == 3)
        {
            running = false;
        }
    }
    return 0;
}