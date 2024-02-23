int findJudge(int n, vector<vector<int>>& trust)
{
   if(n == 1)
      return 1;

   if(trust.empty())
      return -1;

   map<int,int> trusttable;
   int size = static_cast<int>(trust.size());

   buildTable(n,trusttable);
   for(int i=0;i<size;i++)
      trusttable[trust[i][1]] += 1;

   int id = onlyNonzero(n,trusttable);

   if(id != -1)
      return id;
   else
   {
      id = getLargest(n,trusttable);
      if(id != -1 && trustNoone(id,trust))
          return id;
   }

   return -1;
}

int getLargest(int n, map<int,int> &source)
{
   int dups = 0;
   int result = -1;

   for(int i=1;i<=n;i++)
   {
      if(result == -1)
          result = i;
      else
      {
          if(source[i] > source[result])
          {
              result = i;
              if(dups > 0)
                  dups = 0;
          }
          else if(source[i] == 0)
              continue;
          else if(source[i] == source[result])
              dups++;
      }
   }

   if(dups > 0)
      return -1;
   else if(source[result] != (n-1))
      return -1;

   return result;
}

int onlyNonzero(int n, map<int,int> &source)
{
   bool first = false;
   int result; 

   for(int i=1;i<=n;i++)
   {
      if(source[i] > 0)
      {
          if(!first)
          {
              first = true;
              result = i;
          }
          else
              return -1;
      }
   }

   return result;
}

constexpr void buildTable(int n, map<int,int> &destination)
{
   for(int i=1; i<=n; i++)
      destination[i] = 0;
}

bool trustNoone(int id, vector<vector<int>> &source)
{
   int size = static_cast<int>(source.size());
   for(int i=0;i<size;i++)
   {
      if(source[i][0] == id)
          return false;
   }
   return true;
}