/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:  smallestFromLeaf
// Last Modified:  April 17th, 2024
// Author:  Jason A Biddle
//
// Purpose:  returns the smallest possible string built starting from a leaf
//           node.
//
// In:  root - The head of the tree we're using to build the string.
//
// Out:  The lexicographically smallest string.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string smallestFromLeaf(TreeNode* root)
{
    vector<char> current;  //Used by buildStrings as the currently built string.
    buildStrings(root,current);  //Time to build them strings!
    sort(results.begin(),results.end());  //Sort them when we're done.

    //Return the smallest.
    return results[0];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Function:  buildStrings
// Last Modified:  April 17th, 2024
// Author:  Jason A Biddle
//
// Purpose:  Builds all possible strings using the given root.
//
// In:  node - The current position with the tree.
//      current - The string we're building.
//
// Out:  None
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void buildStrings(TreeNode *node, vector<char> &current)
{
    //Are we a leaf?
    if(node->left == nullptr && node->right == nullptr)
    {
        //If so build the string and push it to the results vector.
        string resString;
        resString.push_back((char)(node->val + 97));
        int size = (int)current.size();
        for(int i = size - 1; i>=0; i--)
            resString += current[i];
        results.push_back(resString);
        return;
    }

    //If we're not a leaf add this nodes val and move on.
    current.push_back((char)(node->val + 97));

    if(nodey->left != nullptr)
        buildStrings(node->left,current);
    if(node->right != nullptr)
        buildStrings(node->right,current);

    //remove this nodes value after we've exhausted all child nodes.
    current.pop_back();

}

private:
    vector<string> results;  //Where we store all constructed strings.
