class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {

        long long cost = 0;
        cost += 1LL * min(cost1 + cost2, costBoth) * min(need1, need2);

        if (need1 >= need2) {
            need1 -= need2;
            if (costBoth >= cost1) {
                cost += 1LL*cost1 * need1;
            } else {
                cost += 1LL*costBoth * need1;
            }
        } else {
            need2-=need1;
            if (costBoth >= cost2) {
                cost += 1LL*cost2 * need2;
            } else {
                cost += 1LL*costBoth * need2;
            }
        }

        return cost;
    }
};
