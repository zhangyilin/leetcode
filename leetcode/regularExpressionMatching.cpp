#include <iostream>
using namespace std;
class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function    
            if (*s == '\0'){
                if (*p == '\0'){
                    return true;
                }else{
                    while (*p != '\0'){
                        if (*p == '*'|| *(p+1)=='*'){
                            p++;
                        }else{
                            return false;
                        }
                    }
                    return true;
                }
            }

            if (*s==*p || *p=='.'){
                if (*(p+1) =='*'){
                    return isMatch(s,p+2)||isMatch(s+1,p+1);
                }
                return isMatch(s+1,p+1);
            }else if (*p == '*'){
                if (*s == *(p-1) || *(p-1)=='.'){
                    return isMatch(s+1,p)||isMatch(s+1,p+1)||isMatch(s,p+1);
                }else{
                    return isMatch(s,p+1);
                }
            }else{
                if (*(p+1)=='*'){
                    return isMatch(s,p+2);
                }
                return false;
            }
        }
};
int main(){
    const char *s = "b";
    const char *p = "";
    Solution S;
    cout<< S.isMatch(s,p);
}
