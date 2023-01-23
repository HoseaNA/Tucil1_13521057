float combination(float numbers[4],char ops[3], int comb)
{
    /* All Possibilities
    ((A B) C) D
    (A (B C)) D
    A (B (C D))
    A ((B C) D)
    (A B) (C D)
    */

    if (comb == 1) /*((A B) C) D*/
    {
        return count(count(count(numbers[0],numbers[1],ops[0]),numbers[2],ops[1]),numbers[3],ops[2]);
    }
    else if (comb == 2) /*(A (B C)) D*/
    {
        return count(count(numbers[0],count(numbers[1],numbers[2],ops[1]),ops[0]),numbers[3],ops[2]);
    }
}

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
        return num1/num2;
    }
    else
    {
        return 1.0;
    }
}