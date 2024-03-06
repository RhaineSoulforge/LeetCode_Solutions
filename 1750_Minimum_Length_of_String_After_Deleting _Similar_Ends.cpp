int minimumLength(string s)
{
   //Starting size of the string.
   int length = static_cast<int>(s.length());

   //Setting the front and back points to their starting
   //positions
   int front = 0, back = length - 1;
   char match;

   while(true)
   {
      //If string is empty or of length 1 then break out of the loop.
      if(length == 0 || length == 1)
         break;

      //If the front and back characters don't match then we're done.
      if(s[front] != s[back])
         break;

      //Grab the character we're matching with from the head of the
      //string.
      match = s[0];

      //While the back pointer matches the current character keep
      //moving the back pointer to the front of the string till we
      //no long match or reach the front of the string.
      while(back >= 0 && s[back] == match)
         back--;

      //While the front pointer matches the current character keep
      //moving the front pointer till the end of string or we no
      //longer match.
      while(front < length && s[front] == match)
         front++;

      //Erase the suffix then prefix from the string.          
      s.erase(back+1);
      s.erase(0,front);

      //Get the new length of the string, reset both the front
      //and back pointers.
      length = static_cast<int>(s.length());
      front = 0;
      back = length - 1;
   }

   //Return the new length of the string.
   return length;
}