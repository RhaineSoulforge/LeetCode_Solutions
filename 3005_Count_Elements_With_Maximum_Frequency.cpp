//My sorting function so that sort() puts it
//in decending order.
static bool MyComp(int left, int right)
{
  return left > right;
}

int maxFrequencyElements(vector<int>& nums)
{
  //Since we know the nums[i] range is 1 to 100
  //we'll created a vector with 101 ints to count
  //frequencies, rather than a map.
  vector<int> frequencies(101,0);

  //Goes through nums incremented frequencies using
  //nums[i] as the index into frequencies.
  int size = (int)nums.size();
  for(int i = 0; i < size; i++)
      frequencies[nums[i]] += 1;

  //Sort into decending order.
  sort(frequencies.begin(),frequencies.end(),MyComp);

  //frequencies[0] is our largest frequency now we
  //add up frequencies until we no longer equal
  //frequencies[0].
  int count = frequencies[0];
  for(int i = 1; i < 100; i++)
  {
      if(frequencies[i] != frequencies[0])
          break;
      count += frequencies[i];
  }

  //Here's the maximum frequency!!
  return count;
}