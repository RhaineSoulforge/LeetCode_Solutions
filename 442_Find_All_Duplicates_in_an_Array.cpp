vector<int> findDuplicates(vector<int>& nums)
{
   unordered_map<int,int> counts;  //Contains count of all numbers in nums.
   vector<int> result;  //Will contain dups only.

   int size = static_cast<int>(nums.size());  //Size of nums.
   for(int i=0;i<size;i++)
   {
      if(counts[nums[i]] >= 1)  //If nums[i] is already in the map, IT'S A DUP!!
         result.push_back(nums[i]);  //Put it in the result vector.
      counts[nums[i]] += 1; //Increment the count for that value.
   }

   return result;
}