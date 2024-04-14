/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:  sumOfLeftLeaves
// Last Modified:  April 14th, 2024
// Author:  Jason A Biddle
//
// Purpose:  returns the sum of all the left leaves.
//
// In:  root - The current node in the tree.
//
// Out:  The sum of all the left leaves.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int sumOfLeftLeaves(TreeNode *root)
{
    //If we're null return 0
    if(!root)
        return 0;

    //Do we have a left child?
    if(root->left)
    {
        //Does the left child have children?
        if(root->left->left == nullptr && root->left->right == nullptr)
            return root->left->val + sumOfLeftLeaves(root->right);
    }

    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}
