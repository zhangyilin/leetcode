class Solution {
public:
    int reverse(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        bool neg = false;
        if (x<0){
            neg = true;
            x = 0-x;
        }
        int rev = 0;
        while (x){
            int bit = x%10;
            x = x/10;
            rev = 10*rev + bit;
        }
        if (neg)    rev = 0-rev;
        return rev;
    }
};
