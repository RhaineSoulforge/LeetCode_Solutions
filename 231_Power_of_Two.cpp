bool isPowerOfTwo(int n)
{
   double result = log2(n);
   double remainder = result - floor(result);
   if(remainder == 0.0)
      return true;

   return false;
}