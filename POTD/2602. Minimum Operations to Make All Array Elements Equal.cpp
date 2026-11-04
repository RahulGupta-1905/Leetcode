
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {

        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<long long> prefixSum(n);
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        vector<long long> ans;
        for (auto query : queries) {

            auto it = upper_bound(nums.begin(), nums.end(), query);
            int idx = it - nums.begin();

            int left = idx;
            int right = n - idx;
            long long leftSum = (idx > 0 ? prefixSum[idx - 1] : 0);
            long long rightSum = prefixSum[n - 1] - leftSum;

            long long leftOps = 1LL * left * query - leftSum;
            long long rightOps = rightSum - 1LL * right * query;

            ans.push_back(leftOps + rightOps);
        }

        return ans;
    }
};
