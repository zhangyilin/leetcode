class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function    
            int m=strlen(s);
            int n=strlen(p);
            bool dp[1000][1000] = {false};//dp[i][j] means last i chars in s matches last j chars in p
            dp[0][0] = true;
            for (int i=1; i<=n; ++i){
                dp[0][i] = dp[0][i-1]&&*(p+n-i)=='*'?true:false;
            }
            for (int i=1; i<=m; ++i){
                dp[i][0] = false;
            }
            for (int i=1; i<=n; ++i){
                char p_c = *(p+n-i);
                for (int j=1; j<=m; ++j){
                    char s_c = *(s+m-j);
                    if (p_c == '*'){
                        for (int k=0; k<=j; ++k){
                            dp[j][i] = dp[j][i] || dp[k][i-1];
                        }
                    }else if (p_c == '?' || p_c==s_c){
                        dp[j][i] = dp[j-1][i-1];
                    }else{
                        dp[j][i] = false;
                    }
                }
            }
            return dp[m][n];
        }
};
