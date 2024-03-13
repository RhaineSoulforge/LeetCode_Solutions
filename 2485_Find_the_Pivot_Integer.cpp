int pivotInteger(int n)
{   
   //Take the square root of the sum of the arithmatic series n,
   //if there's no remainder then result is our pivot.
   double result = sqrt((n / 2.0) * (2.0 + (n-1.0)));
   if(fmod(result,1.0) == 0)
      return result;

   //Otherwise return -1;
   return -1;
}