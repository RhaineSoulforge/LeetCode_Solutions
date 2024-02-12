vector<vector<string>> groupAnagrams(vector<string>& strs)
{
   vector<vector<string>> results;
   unordered_map<string,vector<string>> subResults;
   string sorted;

   int size = (int)strs.size();
   for(int i=0; i<size; i++)
   {
      sorted = strs[i];
      MergeSort(sorted,0,(int)sorted.length()-1);
      subResults[sorted].push_back(strs[i]);
   }

   unordered_map<string,vector<string>>::const_iterator current = subResults.begin();
   unordered_map<string,vector<string>>::const_iterator end = subResults.end();
   while(current != end)
   {
      results.push_back(current->second);
      current++;
   }

   return results;
}        

void MergeSort(string &source, int left, int right)
{
   if(left >= right)
      return;

   int middle = left + (right-left) / 2;

   MergeSort(source,left,middle);
   MergeSort(source,middle + 1,right);
   Merge(source,left,middle,right);
}

void Merge(string &source, int left, int middle, int right)
{
   int leftSize = middle - left + 1;
   int rightSize = right - middle;

   string leftList,rightList;

   for(int i=0;i<leftSize;i++)
      leftList += source[left + i];

   for(int i=0;i<rightSize;i++)
      rightList += source[1 + i + middle];

   int leftPos = 0, rightPos = 0, current = left;
   while(leftPos < leftSize && rightPos < rightSize)
   {
      if(leftList[leftPos] <= rightList[rightPos])
      {
          source[current] = leftList[leftPos];
          leftPos++;
      }
      else
      {
          source[current] = rightList[rightPos];
          rightPos++;
      }
      current++;
   }

   while(leftPos < leftSize)
   {
      source[current] = leftList[leftPos];
      leftPos++;
      current++;
   }

   while(rightPos < rightSize)
   {
      source[current] = rightList[rightPos];
      rightPos++;
      current++;
   }
}
