class Solution {
    public:
        string countAndSay(int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            string s = "1";
            for (int i=1; i<n; ++i){
                int len = s.size();
                string current_s (s, 0, 0);
                int count = 1;
                for (int j=1; j<len; ++j){
                    if (s[j]==s[j-1]){
                        count++;
                    }else{
                        current_s += '0' + count;
                        current_s += s[j-1];
                        count = 1;
                    }
                }
                current_s += '0' + count;
                current_s += s[len-1];
                s = current_s;
            }
            return s;
        }
};
