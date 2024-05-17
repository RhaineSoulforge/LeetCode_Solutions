/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:  removeLeafNodes
// Last Modified:  May 17th, 2024
// Author:  Jason A Biddle
//
// Purpose:  Removes the leaf nodes that contain a given value, if node becomes
//           a leaf and contains that value it is then removed as well.
//
// In:  root - The nodes we're current on in the tree.
//      target - The value that we're targeting.
//
// Out:  A binary tree where all leaves containing the target value have be
//       removed.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TreeNode* removeLeafNodes(TreeNode* root, int target)
{
    //If we're null....
    if(!root)
        return nullptr;

    //Go to the next depth of the tree.
    root->left = removeLeafNodes(root->left,target);
    root->right = removeLeafNodes(root->right,target);

    //Have we become a leaf?
    if(!root->left && !root->right)
    {
        //Is our value the same as target?
        if(root->val == target)
            return nullptr;  //Remove us from the tree!
    }

    return root;
}
