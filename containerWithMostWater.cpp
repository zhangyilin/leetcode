class Solution {
    public:
        int maxArea(vector<int> &height) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int n = height.size();
            int best = (n-1) * min(height.front(), height.back());
            int left = 0;
            int right = n-1;
            while (left <= right){
                int left_val = height[left];
                int right_val = height[right];
                best = max(best, (right-left)*min(left_val, right_val));
                if (left_val < right_val){
                    left++;
                }else{
                    right--;
                }
            }
            return best;
        }
};
