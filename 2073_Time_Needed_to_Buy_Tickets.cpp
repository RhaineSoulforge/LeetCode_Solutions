/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function: 
// Last Modified:  
// Author:  
//
// Purpose:  
//
// In:  
//
// Out:
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
