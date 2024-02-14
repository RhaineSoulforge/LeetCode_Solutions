vector<int> rearrangeArray(vector<int>& nums)
{
   vector<int> positive;
   vector<int> negative;
   int maxSize = (int)nums.size();
   int size = maxSize / 2;

   for(int i=0; i<maxSize; i++)
   {
      if(nums[i] > 0)
          positive.push_back(nums[i]);
      else
          negative.push_back(nums[i]);
   }

   vector<int> result;
   for(int j=0; j<size; j++)
   {
      result.push_back(positive[j]);
      result.push_back(negative[j]);
   }

   return result;
}