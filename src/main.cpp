#include<iostream>
#include<map>
using namespace std;

bool mainMenu()
{
    int choice;
    cout << "Ketik 1 untuk input manual\nKetik 2 untuk input random\n";
    cin >> choice;

    float numbers[4];
    if (choice == 1)
    {
        numsManual(numbers);
    }
    else if (choice == 2)
    {

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
    
}

int main()
{
    
    return 0;
}