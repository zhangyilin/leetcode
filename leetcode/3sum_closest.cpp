class Solution {
    public:
        int threeSumClosest(vector<int> &num, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            sort (num.begin(), num.end());
            int n = num.size();
            int best_sum;
            for (int i = 0; i < n-2; i++){
                int number_1 = num[i];
                int j = i+1;
                int k = n-1;
                while (j<k){
                    int sum = number_1+num[j]+num[k];
                    if (sum == target){
                        return target;
                    }else if(sum < target){
                        if (abs(target-best_sum) > target-sum){
                            best_sum = sum;
                        }
                        j++;
                    }else{
                        if (abs(target-best_sum) > sum-target){
                            best_sum = sum;
                        }
                        k--;
                    }

                }
            }
            return best_sum;

        }
};
