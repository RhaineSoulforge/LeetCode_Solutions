bool isEvenOddTree(TreeNode* root) {
   unordered_map<int,vector<int>> graph;

   // build graph of Tree.
   buildGraph(0,root,graph);

   unordered_map<int,vector<int>>::const_iterator current = graph.begin();
   unordered_map<int,vector<int>>::const_iterator end = graph.end();
   vector<int>::const_iterator curLevel;
   vector<int>::const_iterator endLevel;
   
   while(current != end)
   {
      bool odd;
      // Not root of tree.
      if(current->first != 0)
      {
          curLevel = current->second.begin();
          endLevel = current->second.end();
          int nextVal;
          odd = current->first % 2;  // Is this index odd or even
          if(odd)
          {
              // If index is odd then we need to check to make sure values are even.
              odd = *curLevel % 2;
              if(odd)
                  return false;
              else
              {
                  // If values even we need to make sure they're decending,
                  // Otherwise return false.
                  while(curLevel != endLevel)
                  {
                      if(curLevel + 1 == endLevel)
                          break;
                      else
                      {
                          nextVal = *(curLevel + 1);
                          odd = nextVal % 2;
                          if(odd)
                              return false;
                          else
                          {
                              if(*curLevel <= nextVal)
                                  return false;
                          }
                      }
                      curLevel++;
                  }
              }
          }
          else
          {
              // If our index is even then we check to make sure all values are odd.
              curLevel = current->second.begin();
              endLevel = current->second.end();
              odd = *curLevel % 2;
              if(odd)
              {
                  // Checking to make sure that the odd vaules are all ascending,
                  // Otherwise return false.
                  while(curLevel != endLevel)
                  {
                      if(curLevel + 1 == endLevel)
                          break;
                      else
                      {
                          nextVal = *(curLevel + 1);
                          odd = nextVal % 2;
                          if(odd)
                          {
                              if(*curLevel >= nextVal)
                                  return false;
                          }
                          else
                              return false;
                      }
                      curLevel++;
                  }
              }
              else
                  return false;

          }
      }
      else
      {
         // If root value is even then return false, otherwise keep going.
         odd = current->second[0] % 2;
         if(!odd)
            return false;
      }
      current++;
   }
   return true;
}

void buildGraph(int index, TreeNode *root, unordered_map<int,vector<int>> &graph)
{
   if(!root)
      return;

   graph[index].push_back(root->val);
   buildGraph(index+1,root->left,graph);
   buildGraph(index+1,root->right,graph);
}