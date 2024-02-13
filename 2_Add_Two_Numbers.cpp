ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
   ListNode *result = nullptr;
   ListNode *current = nullptr;

   int carry = 0;
   int total;
   ListNode *curLeft = l1;
   ListNode *curRight = l2;

   while(true)
   {
      total = 0;
      if(curLeft != nullptr)
      {
          total += curLeft->val;
          curLeft = curLeft->next;
      }
      
      if(curRight != nullptr)
      {
          total += curRight->val;
          curRight = curRight->next;
      }

      total += carry;
      carry = total / 10;
      total = total % 10;

      if(!result)
      {
          result = new ListNode(total);
          current = result;
      }
      else
      {
          current->next = new ListNode(total);
          current = current->next;
      }

      if(curLeft == nullptr && curRight == nullptr)
          break;
   }

   if(carry != 0)
      current->next = new ListNode(carry);

   return result;        
}