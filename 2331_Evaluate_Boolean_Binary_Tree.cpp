/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:  evaluateTree
// Last Modified:  May 16th, 2024
// Author:  Jason A Biddle
//
// Purpose:  Evaluates a binary tree.
//
// In:  root - The current node we're on within the tree.
//
// Out:  The result of the binary tree!
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool evaluateTree(TreeNode* root)
{
    //If value equals 1 or 0 then return that value.
    if(root->val == 1 || root->val == 0)
        return root->val;

    //If root value is 2 this is an OR
    if(root->val == 2)
        return evaluateTree(root->left) || evaluateTree(root->right);

    //Otherwise return an AND result.
    return evaluateTree(root->left) && evaluateTree(root->right);
}
