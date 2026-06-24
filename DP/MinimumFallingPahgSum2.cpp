// Leetcode 1289 Minimum Falling Path Sum 2

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dp(n,vector<int>(n,1e9));

        for(int col=0;col<n;col++) 
            dp[n-1][col]=grid[n-1][col];

        for(int row=n-2;row>=0;row--){
            for(int col=0;col<n;col++){
                int ans=INT_MAX;
                for(int nextCol=0;nextCol<n;nextCol++){
                    if(col!=nextCol){
                        ans=min(ans,dp[row+1][nextCol]);
                    }
                }
                dp[row][col]=grid[row][col]+ans;
            }
        }


        int result=INT_MAX;
        for(int col=0;col<n;col++)
            result=min(result,dp[0][col]);
        
        return result;

    }
};
