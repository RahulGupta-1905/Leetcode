class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int lsi = 1;
        int ans = INT_MIN;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                lsi++;
            } else {
                ans = max(ans, lsi);
                lsi = 1;
            }
        }
        ans = max(ans, lsi);

        int lsd = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                lsd++;
            } else {
                ans = max(ans, lsd);
                lsd = 1;
            }
        }
        ans = max(ans, lsd);

        return ans;
    }
};
