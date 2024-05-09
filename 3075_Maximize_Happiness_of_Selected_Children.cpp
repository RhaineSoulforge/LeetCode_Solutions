/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:  maximumHappinessSum
// Last Modified:  May 9th, 2024
// Author:  Jason A Biddle
//
// Purpose:  Returns to maximum happiness of k children.
//
// In:  happiness - The happiness value of the children currently
//      in line.
//      k - The number of children to be choosen.
//
// Out:  The maximum amount of happiness.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
long long maximumHappinessSum(vector<int>& happiness, int k)
{
    //Get the size of the queue.
    int size = static_cast<int>(happiness.size());

    //Running total of happiness.
    long long result = 0;

    //Sort queue into ascending order.
    sort(happiness.begin(),happiness.end());

    //Starting at the tail of the queue, add the happiness value minus
    //the number of times through the queue.
    for(int i=size-1,j=0; j<k; i--,j++)
    {
        //If j is less than happiness of a given childen then
        //add it to the result(We don't want negitive values).
        if(j < happiness[i])
            result += happiness[i] - j;
    }

    return result;
}
