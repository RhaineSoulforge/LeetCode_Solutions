#include <vector>
#include <algorithm>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:  heightChecker
// Last Modified:  June 10th, 2024
// Author:  Jason A Biddle
//
// Purpose:  Given an array Heights this function returns the number of times where
//           Heights[i] != Expected[i].
//
// In:  heights - non-decreasing order of heights.
//
// Out:  returns the number of times heights[i] != expected[i].
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int heightChecker(std::vector<int>& heights)
{
    short size = static_cast<short>(heights.size());  //Size of heights array.
    short count = 0;  //Number of times heights don't meet expectation.

    //If heights is size 1 just return 1.
    if(size == 1)
        return 1;

    //Copy heights and sort it into ascending order.
    std::vector<int> expected = heights;
    std::sort(expected.begin(),expected.end());

    //Now lets go through and check to see if everything matches.
    for(short i=0;i<size;i++)
    {
        if(heights[i] != expected[i])
            count++;
    }

    return count;
}

