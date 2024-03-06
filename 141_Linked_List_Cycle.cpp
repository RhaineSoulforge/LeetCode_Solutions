bool hasCycle(ListNode *head)
{
   //The hare moves two nodes ahead of the tortoise,
   //if there is a loop the hare will catch up to the
   //slow moving tortoise.
   ListNode *hare = head;
   ListNode *tortoise = head;
   while(hare && tortoise)
   {
      hare = hare->next;
      if(hare)
         hare = hare->next;
      else
         //Break the loop if the hare gets to the end of the list without looping.
         break;
      tortoise = tortoise->next;

      if(hare == tortoise)
         return true;
   }

   return false;
}