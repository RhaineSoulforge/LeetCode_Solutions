/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:  addOneRow
// Last Modified:  April 16th, 2024
// Author:  Jason A Biddle
//
// Purpose:  add a row of nodes into a Tree with a given value.
//
// In:  root - The start of the tree.
//      val - The value of the all of the nodes for the added row.
//      depth - The depth of the tree where we're adding the row.
//
// Out:  The newly modified tree.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TreeNode* addOneRow(TreeNode* root, int val, int depth)
{
    //If the depth is one we're changing the root to our new node.
    if(depth == 1)
    {
        TreeNode *node = new TreeNode(val,root,nullptr);
        node->left = root;
        root = node;
        return root;
    }

    //Now we traverse to the depth we need to be at.
    addRow(root,val,1,depth);
    return root;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:  addRow
// Last Modified:  April 16th, 2024
// Author:  Jason A Biddle
//
// Purpose:  Traverse through the tree till we hit the desired depth then add
//           the new row.
//
// In:  node - The current node in the tree.
//      val - The value of the new nodes.
//      curDepth - The current depth we're at.
//      targetDepth - The target depth we need to reach.
//
// Out:  None
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void addRow(TreeNode *node, int val, int curDepth, int targetDepth)
{
    //We've reach our target depth now start adding the new row.
    if(curDepth == (targetDepth - 1))
    {
        TreeNode *left = new TreeNode(val,node->left,nullptr);
        TreeNode *right = new TreeNode(val,nullptr,node->right);

        node->left = left;
        node->right = right;
        return;
    }

    //If we can keep going further down then go!
    if(node->left != nullptr)
        addRow(node->left,val,curDepth+1,targetDepth);

    //If we can keep going further down the go!
    if(node->right != nullptr)
        addRow(node->right,val,curDepth+1,targetDepth);
}
