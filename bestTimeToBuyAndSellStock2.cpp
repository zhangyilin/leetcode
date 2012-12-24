/*
   Always purchase if it gonna go up, sell if it goona go down
 */
class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            bool purchased = false;
            int purchase_price = 0;
            int profit = 0;
            int n = prices.size();
            for (int i = 0; i < n-1; ++i){
                if (!purchased){
                    if (prices[i] < prices[i+1]){
                        purchase_price = prices[i];
                        purchased = true;
                    }
                }else{
                    if (prices[i] > prices[i+1]){
                        profit += prices[i] - purchase_price;
                        purchased = false;
                    }
                }
            }
            if (purchased){
                profit += prices[n-1]-purchase_price;
            }
            return profit;
        }
};
