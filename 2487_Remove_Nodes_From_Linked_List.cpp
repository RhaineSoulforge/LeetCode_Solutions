/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:  removeNodes
// Last Modified:  May 6th, 2024
// Author:  Jason A Biddle
//
// Purpose:  Removes nodes from the given list that have a larger value
//           to the right of them.
//
// In:  head - Initially the head of the Linked List, later the current node
//             we're looking at in the list.
//
// Out:  Returns the modified Linked List.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ListNode* removeNodes(ListNode* head)
{
    //If the next node is null we've reached the end of the list.
    if(head->next == nullptr)
        return head;

    //Returns the Node with the largest value.
    ListNode *check = removeNodes(head->next);
    if(check->val > head->val)  //Are we still the largest?
        return check;  //If so we get returned!

    //If not we set the new largest next node to the previous largest node.
    head->next = check;
    return head;
}
