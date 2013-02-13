#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int numDistinct(string S, string T) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int s_len = S.size();
            int t_len = T.size();
            if (s_len<t_len || t_len==0){
                return 0;
            }
            //initialize single char count
            vector<int> current(s_len,0);
            current[0] = S[0]==T[0]?1:0;
            for (int i=1; i<s_len; ++i){
                if (S[i] == T[0]){
                    current[i] = 1+current[i-1];
                }else{
                    current[i] = current[i-1];
                }
            }
            //i is for the length of subsequence from T
            //j is the mark at S
            vector<int> next(s_len,0);
            for (int i=1; i<t_len; ++i){
                next = vector<int> (s_len,0);
                for (int j=i; j<s_len; ++j){
                    if (S[j]==T[i]){
                        next[j] = current[j-1] + next[j-1];
                    }else{
                        next[j] = next[j-1];
                    }

                }
                current = next;
            }
            return current[s_len-1];
        }
};
int main(){
    string S="eee";
    string T="eee";
    Solution s;
    int n = s.numDistinct(S,T);
}
