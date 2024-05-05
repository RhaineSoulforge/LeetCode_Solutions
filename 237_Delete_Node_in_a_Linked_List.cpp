/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:  deleteNode
// Last Modified:  May 5th, 2024
// Author:  Jason A Biddle
//
// Purpose:  Delete the given node without being given the head of the Linked
//           List.
//
// In:  node - The node to remove from the Linked List.
//
// Out: --
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void deleteNode(ListNode* node)
{
    ListNode *prev;
    while(node)
    {
        if(node->next)
        {
            node->val = node->next->val;
            prev = node;
        }
        node = node->next;
    }
    prev->next = NULL;
}
