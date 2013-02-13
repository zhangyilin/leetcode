class Solution {
    public:
        vector<int> twoSum(vector<int> &numbers, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int n = numbers.size();
            vector<int> pair(0);
            vector<int> index(0);
            vector<int> copy = numbers;
            if (n<=0)   return index;
            sort (numbers.begin(), numbers.end());
            int left = 0;
            int right = n-1;
            while (left < right){
                int sum = numbers[left] + numbers[right];
                if (sum == target){
                    pair.push_back(numbers[left]);
                    pair.push_back(numbers[right]);
                    break;
                }else if (sum < target){
                    ++left;
                }else{
                    --right;
                }
            }
            for (int i=0; i<n; ++i){
                if (copy[i]==pair[0] || copy[i]==pair[1]){
                    index.push_back(i+1);
                }
            }
            return index;
        }
};
