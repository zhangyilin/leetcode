//Not pass, but meaningless to pass
class Solution {
    public:
        int atoi(const char *str) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            long long n=0;
            bool positive = true;
            while (*str != '\0'){
                if (*str==' ' || *str=='+'){
                    str++;
                    continue;
                }
                if (*str == '-'){
                    positive = false;
                    str++;
                    continue;
                }
                if (*str == '0' && n==0){
                    str++;
                    continue;
                }
                n *= 10;
                n += *str - '0';
                str++;
            }
            if (!positive)  n = -n;
            return n;
        }
};
