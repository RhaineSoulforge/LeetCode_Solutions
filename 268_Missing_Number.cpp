int missingNumber(vector<int>& nums)
{
   sort(nums.begin(),nums.end());
   int size = (int)nums.size();
   int result = 0;

   for(int i=0; i<size; i++)
   {
      if(result != nums[i])
          break;
      
      result++;
   }

   return result;
}