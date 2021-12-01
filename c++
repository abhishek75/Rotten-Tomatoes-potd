 queue<pair<int,int>> q;
       int r = grid.size();
       int c = grid[0].size();
       int x[4] = {0,0,1,-1};
       int y[4] = {1,-1,0,0};
       int ans = -1;
       int fresh = 0;
       for(int i=0;i<r;i++)
       {
           for(int j=0;j<c;j++)
           {
               if(grid[i][j] == 2)
                   q.push({i,j});
               else if(grid[i][j] == 1)
                   fresh++;
           }
       }
       while(!q.empty()){
           int size = q.size();
           while(size--)
           {
               auto it = q.front();
               q.pop();
               int f = it.first;
               int s = it.second;
               for(int k=0;k<4;k++)
               {
                   int fp = f + x[k];
                   int sp = s + y[k];
                   if((fp>=0 and fp<r) and (sp>=0 and sp<c))
                   {
                       if(grid[fp][sp]==1)
                       {
                           fresh--;
                           grid[fp][sp] = 2;
                           q.push({fp,sp});
                       }
                   }
               }
           }
           ans++;
       }
       if(fresh) return -1;
       return ans;
