ListNode* removeNthFromEnd(ListNode* head, int n)
{
   if(!head->next)
      return nullptr;
   int count = doIt(head,head->next,n);
   count++;

   if(count == n)
      head = head->next;

   return head;
}

int doIt(ListNode *prev, ListNode *current, int n)
{
   int count = 1;
   if(current->next)
      count += doIt(current,current->next,n);

   if(count == n)
      prev->next = current->next;

   return count;
}