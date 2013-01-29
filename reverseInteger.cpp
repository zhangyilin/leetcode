class Solution {
    public:
        int reverse(int x) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            bool positive = x>=0?true:false;
            int y=0;
            x = abs(x);
            while (x){
                int digit = x%10;
                y *= 10;
                y += digit;
                x /= 10;
            }
            y = positive?y:-y;
            return y;
        }
};
