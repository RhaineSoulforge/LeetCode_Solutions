string maximumOddBinaryNumber(string s)
{
   //Grab length of string.
   int length = static_cast<int>(s.length());

   //If length is one then just return the string.
   if(length == 1)
      return s;

   //Setting up index points for forward and reverse iterator through string.
   int left = 0, right = length - 1;

   //Lets make sure that the last value in the string is a 1.
   if(s[right] == '0')
   {
      while(left < length && s[left] != '1')
          left++;
      if(left == length)
          return s;
      else
      {
          s[left] = '0';
          s[right] = '1';
      }
   }

   //Move from the back of the string to the front moving any ones we
   //find to the front of the string.
   right--;
   for(left = 0; right > left; right--)
   {
      if(s[right] == '1')
      {
          while(left < right)
          {
              if(s[left] == '0')
              {
                  s[left] = '1';
                  s[right] = '0';
                  break;
              }
              left++;
          }
      }
   }

   return s;
}
