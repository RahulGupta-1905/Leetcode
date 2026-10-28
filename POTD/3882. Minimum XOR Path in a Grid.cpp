class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int maxi=1024;
        vector<vector<vector<bool>>>dp(m,vector<vector<bool>>(n,vector<bool>(maxi,false)));
        dp[0][0][grid[0][0]]=true;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int x=0;x<maxi;x++){
                    if(!dp[i][j][x]) continue;
                    if(i+1<m){
                        dp[i+1][j][x^grid[i+1][j]]=true;
                    }
                    if(j+1<n){
                        dp[i][j+1][x^grid[i][j+1]]=true;
                    }
                }
            }
        }

        int ans=1e9;
        for(int x=0;x<maxi;x++){
            if(dp[m-1][n-1][x]){
                ans=min(x,ans);
            }
            
        }

        return ans;
    }
};
