vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
   vector<int> result;
   int sizeA = (int)nums1.size();
   int sizeB = (int)nums2.size();

   //If nums1 is larger than nums2 then nums1 will be the outer loop.
   if(sizeA > sizeB)
   {
      for(int i=0;i<sizeA;i++)
      {
          for(int j=0;j<sizeB;j++)
          {
              //Are we equal?
              if(nums1[i] == nums2[j])
              {
                  //If so then are we already in the result list?
                  if(find(result.begin(),result.end(),nums1[i]) == result.end())
                      result.push_back(nums1[i]); //We're not so in the list we go!
                  break;
              }
          }
      }
   }
   else
   {
      for(int i=0;i<sizeB;i++)
      {
          for(int j=0;j<sizeA;j++)
          {
              //Are we equal?
              if(nums2[i] == nums1[j])
              {
                  //If so then are we already in the result list?
                  if(find(result.begin(),result.end(),nums2[i]) == result.end())
                      result.push_back(nums2[i]); //We're not so in the list we go!
                  break;
              }
          }
      }
   }

   return result;
}