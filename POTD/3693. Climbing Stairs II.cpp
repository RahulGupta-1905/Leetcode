class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {

        vector<int> dp(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {

            int cost1 = INT_MAX;
            int cost2 = INT_MAX;
            int cost3 = INT_MAX;

            if(i + 1 <= n)
                cost1 = costs[i] + 1 + dp[i + 1];

            if(i + 2 <= n)
                cost2 = costs[i + 1] + 4 + dp[i + 2];

            if(i + 3 <= n)
                cost3 = costs[i + 2] + 9 + dp[i + 3];

            dp[i] = min({cost1, cost2, cost3});
        }

        return dp[0];
    }
};
