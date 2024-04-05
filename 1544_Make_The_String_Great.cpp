/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function: makeGood
// Last Modified:  April 5th, 2024
// Author:  Jason A Biddle
//
// Purpose:  Removes all characters that are next to their upper or lower case
//           equivalent.
// In:  s - The String to be modified.
//
// Out:  result - The good string.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string makeGood(string s)
{
   //Length of starting string.
   int length = static_cast<int>(s.length());
   
   //If length is 0 or 1 just return the base string.
   if(length == 0 || length == 1)
      return s;

   //Did we changed the string during the loop?
   bool bChanged;
   string result = s;  //Set result to base string.
   do
   {
      bChanged = false;  //We haven't made a change.
      
      //Set length to the length of the string minus 1.
      length = static_cast<int>(result.length()) - 1;
      for(int i=0; i<length; i++)
      {
         //Are the characters the same?
         if(tolower(result[i]) == tolower(result[i+1]))
         {
            //Is one upper case and the other lower case?
            if((!isupper(result[i]) && isupper(result[i+1])) ||
            (!isupper(result[i+1]) && isupper(result[i]))
            )
            {
               //If they are delete both characters.
               result.erase(i,1);
               result.erase(i,1);
               
               //Reset set the length so we don't go out of bounds.
               length = static_cast<int>(result.length()) - 1;
               
               //Set change to true if this is the first change we've made.
               if(!bChanged)
                   bChanged = true;
            }
         }
      }
   } while(bChanged);

   //Return the good string.  :)
   return result;
}
