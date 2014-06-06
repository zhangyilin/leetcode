class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n<0 || k<0 || n<k)    return vector<vector<int> >(0, vector<int>(0));
        if (k==0)   return vector<vector<int> >(1, vector<int>(0));
        vector<vector<int> > all_in_n_1 = combine(n-1,k);
        vector<vector<int> > k_1_in_n = combine(n-1,k-1);
        for (int i=0; i<k_1_in_n.size(); ++i){
            vector<int> v = k_1_in_n[i];
            v.push_back(n);
            all_in_n_1.push_back(v);
        }
        return all_in_n_1;
        
    }
};
