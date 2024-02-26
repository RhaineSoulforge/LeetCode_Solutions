int firstMissingPositive(vector<int>& nums)
{
   unordered_set<int> contains;

   // Put all unique numbers into a set
   for(int i=0;i<nums.size();i++)
      contains.insert(nums[i]);

   // Start at one and see if i is in the set
   for(int i=1;;i++)
   {
      // If it's not then this is our smallest missing positive integer!
      if(contains.find(i) == contains.end())
         return i;
   }

   return 0;
}