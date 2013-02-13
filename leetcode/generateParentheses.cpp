class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if (n==0){
                return vector<string> (1,"");
            }else if (n==1){
                return vector<string> (1,"()");
            }
            vector<string> vs_short = generateParenthesis(n-1);
            vector<string> vs(0);
            for (int i=0; i<vs_short.size(); ++i){
                string s = vs_short[i];
                int stk = 0;
                for (int j=0; j<s.size(); ++j){
                    if (stk==0){
                        vs.push_back("("+s.substr(0,j)+")"+s.substr(j,s.size()-j));
                    }
                    if (s[j]=='('){
                        stk++;
                    }else if (s[j]==')'){
                        stk--;
                    }
                }
                vs.push_back("("+s+")");
            }
            return vs;
        }
};
