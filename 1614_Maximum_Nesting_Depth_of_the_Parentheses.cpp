int maxDepth(string s)
{
   int length = (int)s.length();  // Length of string.

   // If string is empty or length of one return zero.
   if(length == 0 || length == 1)
      return 0;

   int count = 0;  // Current number of opening (.
   int result = 0; // Maxium number of ().

   for(int i=0; i<length; i++)
   {
      if(s[i] == '(')  // Increase the number of openings.
         count++;
      else if(s[i] == ')')  // Decrease the number of openings.
      {
         // If count is bigger than current max, count becomes new max!
         if(count > result)  
            result = count;
         count--;
      }
   }

   return result;
}