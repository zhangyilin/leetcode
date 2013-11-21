class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int max_profit = 0;
        int cur_min = INT_MAX;
        for (int i=0; i<prices.size(); ++i){
            cur_min = min(cur_min, prices[i]);
            max_profit = max(max_profit, prices[i]-cur_min);
        }
        return max_profit;
    }
};
