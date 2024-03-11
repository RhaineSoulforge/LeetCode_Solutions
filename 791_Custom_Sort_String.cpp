string customSortString(string order, string s)
{
   string result;

   int found;
   int length = (int)order.length();
   //Go through the order string.
   for(int i=0;i<length;i++)
   {
      //For each letter in order find all that exist
      //in s and add it to result.
      found = s.find(order[i]);
      while(found != string::npos)
      {
          result += order[i];
          s = s.erase(found,1);
          found = s.find(order[i]);
      }
   }

   //Add result and what remains of s.
   return result + s;    
}