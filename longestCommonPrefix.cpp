class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            string s="";
            int n = strs.size();
            if (n==0) return s;
            string first = strs[0];
            int l = first.size();
            if (l==0) return s;
            for (int i=0; i<l; ++i){
                char c = first[i];
                int j=1;
                for (j=1; j<n; ++j){
                    if (strs[j][i] != c)    break;
                }
                if (j!=n){
                    return s;
                }else{
                    s += c;
                }
            }
            return s;
        }
};
