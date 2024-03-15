vector<int> productExceptSelf(vector<int>& nums)
{
   //Size of nums.
   int size = static_cast<int>(nums.size());

   //If size is one then return a vector with a
   //zero in it.
   if(size == 1)
   {
      vector<int> result(1,0);
      return result;
   }

   vector<int> result(size,1);
   int product = 1;

   //For all elements in nums set result[i] to the current
   //product and then update product by multipling by the current
   //value in nums.
   for(int i=0;i<size;i++)
   {
      result[i] = product;
      product *= nums[i];
   }

   product = 1;  //Reset
   //Now go back words through nums multipling result[i] by the current
   //product and then updating product by multipling it by the current
   //value of nums[i].
   for(int i=size-1;i>=0;i--)
   {
      result[i] *= product;
      product *= nums[i];
   }

   return result;
}