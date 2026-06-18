2328. Number of Increasing Paths in a Grid

class Solution {
public:
    int n,m;
    const int MOD=1e9+7;
    int dp[1001][1001];
    vector<vector<int>>direction={
        {-1,0},{1,0},{0,-1},{0,1}
    };
    bool isSafe(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int dfs(int i,int j,vector<vector<int>>& grid){
        
        if(dp[i][j]!=-1) return dp[i][j];
        int answer=1;

        for(auto it:direction){
            int new_i=i+it[0];
            int new_j=j+it[1];
            if(isSafe(new_i,new_j) && grid[i][j]>grid[new_i][new_j]){
                answer=(answer%MOD+dfs(new_i,new_j,grid)%MOD)%MOD;
            }
        }
        return dp[i][j]=answer%MOD;
    }
    int countPaths(vector<vector<int>>& grid) {
        
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result=(result%MOD+dfs(i,j,grid)%MOD)%MOD;
            }
        }
        return result%MOD;
    }
};

T.C(n*m);
S.C(n*m)
