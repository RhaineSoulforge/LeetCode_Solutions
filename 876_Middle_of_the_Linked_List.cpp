ListNode* middleNode(ListNode* head) 
{
   int count = 0;
   int mid;
   ListNode *result = head;
   
   //Lets double time it through the linked list
   //in order to get the size of it.
   while(result)
   {
      result = result->next;
      count++;
      if(result)
      {
         result = result->next;
         count++;
      }
   }

   //Find the mid point by first checking is list size is
   //even or odd, once we find that divide it by half and
   //add one if it's even.
   mid = count % 2 ? ceil(count / 2.0f) : (count / 2.0f) + 1;

   //Go back through the list to reach the middle of the
   //list, then return it.
   count = 1; //Reset count
   result = head; //Reset to head of list.
   while(count != mid)
   {
      result = result->next;
      count++;
   }

   return result;
}