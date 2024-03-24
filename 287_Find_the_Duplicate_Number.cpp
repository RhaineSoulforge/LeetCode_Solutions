int findDuplicate(vector<int>& nums)
{
   //Contains the numbers we're already come across!
   unordered_map<int,int> counts;

   int size = (int)nums.size();  //Size of nums
   int result;  //The Duplicate
   
   //while going through the list see if there is already
   //an entry set to 1 if so then set result to the duplicate
   //and break out of the loop!
   for(int i=0;i<size;i++)
   {
      if(counts[nums[i]] == 1)
      {
         result = nums[i];  //Found the dup get out of the loop!
         break;
      }
      else
         counts[nums[i]] = 1;  //Set entry to 1 for that number.
   }

   return result;
}