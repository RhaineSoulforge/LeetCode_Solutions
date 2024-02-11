int countSubstrings(string s)
{
   int count = (int)s.length();
   int length = (int)s.length();
   string check;
   string reversed;

   for(int i=0; i<length; i++)
   {
      if(i+1 == length)
          break;

      check += s[i];
      for(int j = i + 1; j<length; j++)
      {
          check += s[j];
          reversed.resize(check.length());
          reverse_copy(check.begin(),check.end(),reversed.begin());
          if(reversed == check)
              count++;
      }
      check.clear();
   }

   return count;
}