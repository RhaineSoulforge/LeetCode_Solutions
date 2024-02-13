double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
   int sizeLeft = (int)nums1.size();
   int sizeRight = (int)nums2.size();
   int total = sizeLeft + sizeRight;
   int middle = total / 2;
   double median = 0;

   vector<double> result;
   for(int i=0; i<sizeLeft; i++)
   {
      result.push_back(nums1[i]);
      median += (double)nums1[i];
   }

   for(int i=0; i<sizeRight; i++)
   {
      result.push_back(nums2[i]);
      median += (double)nums2[i];
   }

   sort(result.begin(),result.end());

   median /= (double)total;

   return total % 2 == 0 ? (result[middle-1] + result[middle]) / 2.0 : result[middle];
}