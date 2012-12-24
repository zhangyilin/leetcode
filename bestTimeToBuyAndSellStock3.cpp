/*
   Use dp1 and dp2 to record best single transaction <= day i and >=day i.
   Then go through each i to find the maximum combo.
 */
class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if (prices.size() == 0) return 0;
            int n = prices.size();
            int dp1 [n];//max profit if sell on or before day i;
            int dp2 [n];//max profit if purchase on or after day i;
            int min_price = prices[0];
            dp1[0] = 0;
            for (int i=1; i<n; ++i){
                min_price = min (prices[i], min_price);
                dp1[i] = max (dp1[i-1], prices[i]-min_price);
            }
            int max_price = prices[n-1];
            dp2[n-1] = 0;
            for (int i=n-2; i>=0; --i){
                max_price = max (prices[i], max_price);
                dp2[i] = max (dp2[i+1], max_price-prices[i]);
            }
            int max_profit = 0;
            for (int i=0; i<n; ++i){
                max_profit = max (max_profit, dp1[i]+dp2[i]);
            }
            return max_profit;
        }
};
