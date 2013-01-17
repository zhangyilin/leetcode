#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        if (n<=0) return 0;
        int * length = new int [n];
        map<char, int> m;
        for (int i=0; i<n; ++i){
            char c = s[i];
            if (m.find(c) != m.end()){
                length[i] = i-m[c];
                m[c] = i;
            }else{
                length[i] = i+1;
                m[c] = i;
            }
        }
        
        int longest = 0;
        int attached_longest = 0;
        for (int i=0; i<n; ++i){
            attached_longest = min(length[i], 1+attached_longest);
            longest = max(longest, attached_longest);
        }
        delete [] length;
        return longest;
    }
};
int main(){
    string s = "abcd";
    Solution sol;
    cout<< sol.lengthOfLongestSubstring(s)<< endl;
}
