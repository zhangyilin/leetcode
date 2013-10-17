class Solution {
public:
    void buildDP (const vector<int> &prices, vector<int> &dp1, vector<int> &dp2){//prices.size() > 0
        int n = prices.size();
        int lowest = prices[0];
        dp1[0] = 0;
        for (int i=1; i<n; ++i){
            int profit = prices[i]-lowest;
            lowest = min(lowest, prices[i]);
            dp1[i] = max(dp1[i-1], profit);
        }
        int highest = prices[n-1];
        dp2[n-1] = 0;
        for (int i=n-2; i>=0; --i){
            int profit = highest - prices[i];
            highest = max(highest, prices[i]);
            dp2[i] = max(dp2[i+1], profit);
        }
    }
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = prices.size();
        if (n==0)   return 0;
        vector<int> dp1(n,0), dp2(n,0);
        buildDP (prices, dp1, dp2);
        int max_profit = 0;
        for (int i=0; i<n; ++i){
            max_profit = max(max_profit, dp1[i]+dp2[i]);
        }
        return max_profit;
    }
};
