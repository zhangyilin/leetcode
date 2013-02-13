class Solution {
    public:
        string longestPalindrome(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int n = s.size();
            if (n==0)   return "";
            int table[1000][1000] = {false};
            for (int i=0; i<n; ++i){
                table[i][i] = true;
            }
            for (int size=2; size<=n; ++size){
                for (int left=0; left+size-1<n; ++left){
                    int right = left+size-1;
                    if (s[left]==s[right]){
                        if (table[left+1][right-1] || left+1 > right-1){
                            table[left][right] = true;
                        }
                    }
                }
            }
            for (int size=n; size>0; --size){
                for (int left=0; left+size-1<n; ++left){
                    int right = left+size-1;
                    if (table[left][right]){
                        return s.substr(left,right-left+1);
                    }
                }
            }
        }
};
