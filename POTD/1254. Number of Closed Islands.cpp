class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int m,n;
    bool isPossible(int row,int col,vector<vector<int>>& grid,vector<vector<bool>>&vis){
        vis[row][col]=true;
        queue<pair<int,int>>q;
        q.push({row,col});


        bool isClosed=true;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
            
            for(int i=0;i<4;i++){
                int newR=row+dx[i];
                int newC=col+dy[i];

                if(newR<0 || newR>=m || newC<0 || newC>=n){
                    isClosed=false;
                }
                else if(grid[newR][newC]==0 && !vis[newR][newC]){
                    q.push({newR,newC});
                    vis[newR][newC]=true;
                }
            }
        }

        return isClosed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();

        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    if(isPossible(i,j,grid,vis)) cnt++;
                }
            }
        }  
        return cnt;
    }
};
