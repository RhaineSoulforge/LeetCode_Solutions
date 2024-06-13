#include <iostream>
#include <vector>
#include <string>
#include <sstream>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:  sortColors
// Last Modified:  June 13th, 2024
// Author:  Jason A Biddle
//
// Purpose:  Sorts, in place, an array of colors in order 0(red), 1(white), 2(blue) using
//           bubble sort.
//
// In:  nums - The list of unsorted colors.
//
// Out:
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sortColors(std::vector<int> &nums)
{
    bool swapped = true;  //Whether we swapped values.
    short size = static_cast<short>(nums.size())-1; //Size of list minus one.
    while(swapped)  //Do this till we haven't anything to sort.
    {
        swapped = false;  //New loop set to false.
        for(short i=0;i<size;i++)
        {
            if(nums[i+1] < nums[i]) //If the next color is less than the current color swap them!
            {
                nums[i+1] = nums[i] ^ nums[i+1];
                nums[i] = nums[i] ^ nums[i+1];
                nums[i+1] = nums[i] ^ nums[i+1];
                swapped = true;
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function: to_string
// Last Modified:  June 13th, 2024
// Author:  Jason A Biddle
//
// Purpose:  Returns the string version of the passed in vector.
//
// In:  nums - The vector to be converted.
//
// Out:  buffer - The string representation of the given vector.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const std::string to_string(const std::vector<int> &nums)
{
    std::stringstream buffer;
    buffer << '[';
    short size = static_cast<short>(nums.size());
    for(short i=0; i<size; i++)
    {
        if(i+1 == size)
            buffer << nums[i];
        else
            buffer << nums[i] << ", ";
    }
    buffer << ']';
    return buffer.str();
}

int main(int argc, char **argv)
{
    // Test Case 1
    std::vector<int> colors = {2,0,2,1,1,0};
    sortColors(colors);
    std::cout << "Test Case 1:= " << to_string(colors) << std::endl;

    // Test Case 2
    colors = {2,0,1};
    sortColors(colors);
    std::cout << "Test Case 1:= " << to_string(colors) << std::endl;
}
