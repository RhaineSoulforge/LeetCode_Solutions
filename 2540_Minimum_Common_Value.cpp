int getCommon(vector<int> &nums1, vector<int> &nums2)
{
   //If the largest is nums1 is smaller than the smallest of
   // nums2 then these lists don't intersect.
   if(*nums1.rbegin() < *nums2.begin())
      return -1;

   //Get the largest list.
   int largest = nums1.size() > nums2.size() ? (int)nums1.size() : (int)nums2.size();
   
   //Create a new vector of the largest size.
   vector<int> result(largest,0);
   
   //Find the intersection between the two list.
   vector<int>::iterator end = set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),result.begin());
   
   //Resize the results so we only have real values.
   result.resize(end-result.begin());

   //If the resulting list isn't empty then return
   //the first value aka the Minimum Common value.
   if(!result.empty())
      return result[0];

   return -1;
}