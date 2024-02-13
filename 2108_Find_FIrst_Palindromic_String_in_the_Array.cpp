string firstPalindrome(vector<string>& words)
{
   int size = (int)words.size();

   string reversed;

   for(int i=0; i<size; i++)
   {
      reversed.resize(words[i].length());
      reverse_copy(words[i].begin(),words[i].end(),reversed.begin());
      if(reversed == words[i])
          return words[i];
   }

   return "";
}