/*
   Keep track of max_profit and minimum price so far
   */
class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if (prices.size() == 0){
                return 0;
            }
            int current_min = prices[0];
            int max_profit = 0;
            for (int i=0; i<prices.size(); ++i){
                max_profit = max (max_profit, prices[i]-current_min);
                current_min = min (current_min, prices[i]);
            }
            return max_profit;
        }
};
