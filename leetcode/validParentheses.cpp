class Solution {
    public:
        bool isLeft (char c){
            return c=='(' || c=='[' || c=='{';
        }
        bool isRight (char c){
            return c==')' || c==']' || c=='}';
        }
        bool isPair (char c1, char c2){
            return (c1=='('&&c2==')') || (c1=='['&&c2==']') || (c1=='{'&&c2=='}');
        }
        bool isValid(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int n = s.size();
            vector<char> stk;
            for (int i=0; i<n; ++i){
                char c = s[i];
                if (isRight(c)){
                    if (stk.empty()) return false;
                    char stk_c = stk.back();
                    if (isPair(stk_c,c)){
                        stk.pop_back();
                        continue;
                    }else{
                        return false;
                    }
                }else{
                    stk.push_back(c);
                }
            }
            if (!stk.empty()) return false;
            else return true;
        }
};
