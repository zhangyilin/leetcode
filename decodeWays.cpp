class Solution {
    public:
        int numDecodings(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int n = s.length();
            if (n<1){
                return 0;
            }
            if (n==1){
                if (s[0]=='0'){
                    return 0;
                }else{
                    return 1;
                }
            }
            int s_0 = 1;
            int s_1;
            if (s[n-1] == '0'){
                s_1 = 0;
            }else{
                s_1 = 1;
            }


            int total=0;
            for (int i=n-2; i>=0; --i){
                total = 0;
                int two_digits = 10*(s[i]-'0') + (s[i+1]-'0');
                if (two_digits >= 10){
                    total += s_1;
                }
                if (two_digits<=26 && two_digits>9){
                    total += s_0;
                }
                s_0 = s_1;
                s_1 = total;
            }
            return s_1;
        }
};
