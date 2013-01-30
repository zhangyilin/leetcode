class Solution {
    public:
        bool isPalindrome(int x) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if (x<0){
                return false;
            }
            int x_copy=x;
            int y=0;
            while (x){
                int bit = x%10;
                x = x/10;
                y*=10;
                y+=bit;
            }
            if (x_copy-y==0){
                return true;
            }else{
                return false;
            }
        }
};
