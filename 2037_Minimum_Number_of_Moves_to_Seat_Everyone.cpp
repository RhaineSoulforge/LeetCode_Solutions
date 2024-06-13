#include <iostream>
#include <vector>
#include <algorithm>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:  minMovesToSeat
// Last Modified:  June 13th, 2024
// Author:  Jason A Biddle
//
// Purpose:  Returns the minimum number of moves need to get all the students into
//           their proper seats.
//
// In:  seats - The list of seats.
//      students - The list of students by which seat they're currently sitting in.
//
// Out:  Minimum number of moves made to get the students into the existing seats.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int minMovesToSeat(std::vector<int> &seats, std::vector<int> &students)
{
    int count = 0;
    short size = static_cast<short>(seats.size());  //Number of seats equals Number of students

    //Only sort if there is more than one seat....
    if(size > 1)
    {
        std::sort(seats.begin(),seats.end());
        std::sort(students.begin(),students.end());
    }

    short direction = 0;  //How many seats we need to move that student.
    for(short i=0;i<size;i++)
    {
        direction = students[i] - seats[i];

        if(direction < 0)  //Need to move the student to the left by direction seats.
        {
            students[i] -= direction;
            count += -1 * direction;
        }
        else  //Otherwise move the student to the right by direction seats.
        {
            students[i] -= direction;
            count += direction;
        }
    }

    return count;  //Number of moves we made in total.
}

int main(int argc, char **argv)
{
    //Test case 1
    std::vector<int> seats = {3,1,5};
    std::vector<int> students = {2,7,4};

    std::cout << "Test Case 1:= " << minMovesToSeat(seats,students) << std::endl;

    //Test case 2
    seats = {4,1,5,9};
    students = {1,3,2,6};

    std::cout << "Test Case 2:= " << minMovesToSeat(seats,students) << std::endl;

    //Test case 3
    seats = {2,2,6,6};
    students = {1,3,2,6};

    std::cout << "Test Case 3:= " << minMovesToSeat(seats,students) << std::endl;
}
