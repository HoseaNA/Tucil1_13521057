#include "converter.h"

float convertToNum(char num)
{
    switch (num)
    {
    case 'A':
        return 1.0;
        break;
    case 'J':
        return 11.0;
        break;
    case 'Q':
        return 12.0;
        break;
    case 'K':
        return 13.0;
        break;
    case '2':
        return 2.0;
        break;
    case '3':
        return 3.0;
        break;
    case '4':
        return 4.0;
        break;
    case '5':
        return 5.0;
        break;
    case '6':
        return 6.0;
        break;
    case '7':
        return 7.0;
        break;
    case '8':
        return 8.0;
        break;
    case '9':
        return 9.0;
        break;
    case '10':
        return 10.0;
        break;
    default:
        return 0.0;
        break;
    }
}