class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int n = digits.size();
            if(n == 0)  return vector<string> (1,"");

            map<int, string> m;
            m.insert(make_pair<int,string>(2,"abc"));
            m.insert(make_pair<int,string>(3,"def"));
            m.insert(make_pair<int,string>(4,"ghi"));
            m.insert(make_pair<int,string>(5,"jkl"));
            m.insert(make_pair<int,string>(6,"mno"));
            m.insert(make_pair<int,string>(7,"pqrs"));
            m.insert(make_pair<int,string>(8,"tuv"));
            m.insert(make_pair<int,string>(9,"wxyz"));

            vector<string> comb(1,"");

            for (int i=0; i<n; ++i){
                int dig = digits[i] - '0';
                string s = m[dig];
                vector<string> next_comb(0);
                for (int j=0; j<s.size(); ++j){
                    char c = s[j];
                    vector<string> copy = comb;
                    for (int k=0; k<copy.size(); ++k){
                        copy[k] += c;
                    }
                    next_comb.insert(next_comb.end(), copy.begin(), copy.end());
                }
                comb = next_comb;
            }
            return comb;
        }
};
