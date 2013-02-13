class Solution {
    public:
        int climbStairs(int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if (n<=0) return 0;
            if (n==1) return 1;
            int s0 = 1;
            int s1 = 1;
            int current = 1;
            while (current < n){
                int temp = s0 + s1;
                s0 = s1;
                s1 = temp;
                current++;
            }
            return s1;
        }
};

