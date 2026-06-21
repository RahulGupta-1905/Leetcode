// 2742. Painting the Walls
class Solution {
public:
    int W,N;
    int dp[501][501];
    int solve(int i,int W,vector<int>& cost, vector<int>& time){
        if(W<=0) return 0;
        if(i>=N) return 1e9;
        if(dp[i][W]!=-1) return dp[i][W];
        int paint_i=cost[i]+solve(i+1,W-1-time[i],cost,time);
        int not_paint_i=solve(i+1,W,cost,time);

        return dp[i][W]= min(paint_i,not_paint_i);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        N=cost.size();
        W=cost.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,W,cost,time);
    }
};
