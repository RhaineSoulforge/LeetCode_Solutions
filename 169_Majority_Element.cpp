int majorityElement(vector<int>& nums)
{
   sort(nums.begin(),nums.end());


   int size = (int)nums.size();
   int value = 0;
   int count = 0;
   pair<int,int> highest;
   
   for(int i = 0; i<size;)
   {
      value = nums[i];
      count = 1;

      while(i < size && nums[i] == value)
      {
          count++;
          i++;
      }
      
      if(count > highest.second)
      {
          highest.first = value;
          highest.second = count;
      }
   }
   
   return highest.first;
 }