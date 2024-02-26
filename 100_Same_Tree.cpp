bool isSameTree(TreeNode* p, TreeNode* q)
{
   // If both leaves are null then we're reached the end of a branch.
   if(p == nullptr && q == nullptr)
      return true;

   // If one of the leaves is null then we dont' match.
   if(p == nullptr || q == nullptr)
      return false;

   // If both vals don't match.
   if(p->val != q->val)
      return false;

   // True is both leaves are not null and the vals are the same.
   return isSameTree(p->left,q->left) & isSameTree(p->right,q->right);
}