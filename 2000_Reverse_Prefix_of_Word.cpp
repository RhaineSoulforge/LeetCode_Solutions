/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:  reversePrefix
// Last Modified:  May 1st, 2024
// Author:  Jason A Biddle
//
// Purpose: Given a 0-indexed string word and a character ch, reverse the segment of word
//          that starts at index 0 and ends at the index of the first occurrence of ch
//          (inclusive). If the character ch does not exist in word, do nothing.
//
// In:  word - The string that we're currently searching through.
//      ch - The character that will end the substring.
//
// Out:  Returns the string with the newly reversed substring.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string reversePrefix(string word, char ch)
{
    // Move through the string looking for ch.
    string::iterator current = word.begin();
    string::iterator end = word.end();
    while(current != end)
    {
        // If we found ch then reverse all the characters from
        // the beginning of the string to current character plus
        // one.
        if(*current == ch)
        {
            reverse(word.begin(),current+1);
            break;
        }
        current++;
    }

    return word;
}
