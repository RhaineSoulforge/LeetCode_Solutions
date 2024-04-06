/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function: minRemoveToMakeValid
// Last Modified:  April 6th, 2024
// Author:  Jason A Biddle
//
// Purpose:  Removes unneeded parentheses from a given string.
//           
// In:  s - The String to be modified.
//
// Out:  s - The newly modified string.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string minRemoveToMakeValid(string s)
{
   int length = (int)s.length();  //Length of s.
   stack<int> paren;  //Tracks position of open parentheses.

   for(int i=0; i<length;)
   {
      //If it's opening push position onto stack.
      if(s[i] == '(')
         paren.push(i);
      else if(s[i] == ')')  //Is it a closing parentheses?
      {
         if(paren.empty())  //Is there no matching opening parentheses?
         {
            //Remove it from the string but do not increment i!
            s.erase(i,1);
            length = (int)s.length();  //Update the length of string after removal.
            continue;
         }
         else
            paren.pop();  //Remove the matching open parentheses!
      }
      i++;
   }

   //Do we have any leftover opening parentheses?
   if(!paren.empty())
   {
      //If so remove them from the string!
      while(!paren.empty())
      {
         s.erase(paren.top(),1);
         paren.pop();
      }
   }

   //Return the valid string!
   return s;
}
