#include <iostream>
#include <stdlib.h>
#include <string>

int max = 2147483647;
int min = -2147483648;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:  reverse
// Last Modified:  April 24th, 2024
// Author:  Jason A Biddle
//
// Purpose:  Reverses a given number.
//
// In:  x - The number we're reversing.
//
// Out:  returns the reverse of x, with sign preservered, and if the reverse is less than -2^31 or greater
//       than 2^31 - 1 then we return 0.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int reverse(int x)
{
    //Putting the result in a long long just in case it exceeds boundaries.
    long long result = 0;
    long long copy = x;  //Copy x into a long long so that we can strip the sign.

    //Preserve the sign.
    int sign = 1;
    if(copy < 0)
    {
        sign = -1;
        copy *= -1;
    }

    //Turn our value into a string.
    string strx = to_string(copy);

    //Get the length and then copy value backwards into a new variable
    int length = static_cast<int>(strx.length());
    string backwards;
    for(int i=length-1;i>=0;i--)
        backwards += strx[i];

    //Convert back into a long long and reapply the sign.
    result = stoll(backwards) * sign;

    //If the result is less than min or greater than max return 0!
    if(result < min)
        return 0;
    if(result > max)
        return 0;

    return result;
}

