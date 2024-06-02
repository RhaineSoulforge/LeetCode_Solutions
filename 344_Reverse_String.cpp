/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:  reverseString
// Last Modified:  June 2nd, 2024
// Author:  Jason A Biddle
//
// Purpose:  Reverses a string in place using O(1) memory.
//
// In:  s - The string being reversed.
//
// Out: N/A
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void reverseString(std::vector<char>& s)
{
    char temp;  //Used to temporarily store one of the characters.
    int length = static_cast<int>(s.size());  //Length of string.

    //Two pointer appoarch, while i does not pass j swap them characters!
    for(int i=0, j=length-1; i<j; i++,j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

