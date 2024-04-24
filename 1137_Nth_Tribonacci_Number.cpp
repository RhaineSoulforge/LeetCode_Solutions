/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:  tribonacci
// Last Modified:  April 24th, 2024
// Author:  Jason A Biddle
//
// Purpose:  returns the Nth number in the Tribonnacci sequence!
//
// In:  n - The Nth number that we want the sequence to.
//
// Out:  Nth number in the Tribonnacci sequence.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int tribonacci(int n)
{
    //If return n if it's less than 2.
    if(n < 2)
        return n;
    else if(n == 2)  //Return 1 if n equals 2.
        return 1;

    int a = 0, b = 1, c  = 1, result;

    //For n equal to or greater than 3.
    for(int i=3; i<=n; i++)
    {
        result = a + b + c;
        a = b;
        b = c;
        c = result;
    }

    return result;
}
