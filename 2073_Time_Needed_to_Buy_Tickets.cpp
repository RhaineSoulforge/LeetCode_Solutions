/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:  timeRequiredToBuy 
// Last Modified:  April 9th, 2024
// Author:  Jason A Biddle
//
// Purpose: Calculates the time it takes the kth indivual to buy
//          tickets[k] tickets!
//
// In:  tickets - The queue of people and the amount of tickets they're
//          looking to buy.
//      k - The person in line that we're watching.
//
// Out:  result - The amount of time it took k to by tickets[k] tickets.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int timeRequiredToBuy(vector<int> &tickets, int k)
{
    //Size of the queue.
    int size = static_cast<int>(tickets.size());
    int result = 0;  //Amount of time passed.

    //While our buyer still has tickets to buy.
    while(tickets[k] != 0)
    {
        for(int i=0;i<size;i++)
        {
            //Do we still have tickets to buy?
            if(tickets[i] != 0)
            {
                //If so then decrement amount of tickets to buy,
                //then increment the amount of time that has passed.
                tickets[i]--;
                result++;

                //If we're the person we're observing and we just
                //bought our final ticket, then return the time that
                //passed!
                if(i == k && tickets[i] == 0)
                    return result;
            }
        }
    }

    return result;
}
