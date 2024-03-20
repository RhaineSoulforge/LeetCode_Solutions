ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
{
   ListNode *nodeA = nullptr;
   ListNode *tail = list2;
   ListNode *current = list1;
   int count = 0;
   
   //Get to the end of list2.
   while(tail->next)
      tail = tail->next;

   //While not at the end of list1.
   while(current)
   {
      //If count is one greater than b, then set the end of list2
      //to the remainder of list1.
      if(count == (b+1))
      {
         tail->next = current;
         break;
      }

      //If count is the node before the cut off then save
      //it till we can merge in the head of list2!
      if(count == (a-1))
         nodeA = current;

      current = current->next;
      count++;
   }

   //Merge int list2 plus the remainder of list1 into its
   //new position in list1.
   nodeA->next = list2;

   return list1;
}