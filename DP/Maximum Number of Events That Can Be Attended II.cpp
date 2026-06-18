// 1751. Maximum Number of Events That Can Be Attended II
class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int getNextIdx(int idx, vector<vector<int>>& events) {
    int lo = idx + 1;
    int hi = n - 1;
    int ans = n;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (events[mid][0] > events[idx][1]) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}
    int solve(int idx,int k,vector<vector<int>>& events){
        if(idx>=n) return 0;
        if(k<=0) return 0;
        if(dp[idx][k]!=-1) return dp[idx][k];
        int not_taken=solve(idx+1,k,events);
        int taken=INT_MIN;
        int nextIdx=getNextIdx(idx,events);

        taken=events[idx][2]+solve(nextIdx,k-1,events);

        return dp[idx][k]=max(taken,not_taken);
    }
    int maxValue(vector<vector<int>>& events, int k) {
       n=events.size();
       dp.assign(n+1,vector<int>(k+1,-1));
       sort(events.begin(),events.end());
       return solve(0,k,events); 
    }
};

// T.C(n*k*long)
// S.C(n*k)
