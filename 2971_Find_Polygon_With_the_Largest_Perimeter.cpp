static bool MyComp(int left,int right)
{
   return left > right;
}

long long largestPerimeter(vector<int>& nums)
{
   sort(nums.begin(),nums.end(),MyComp);
   int size = (int)nums.size();

   int j = 0;
   long long length = 0;
   for(int i=0; i<size; i++)
   {
      j = i + 1;
      
      if((size-j) < 2)
          break;

      length = nums[j] + nums[j+1];
      j += 2;

      while(j < size)
      {
          length += nums[j];
          j++;
      }

      if(length > nums[i])
          return length + nums[i];
   }

   return -1;
}