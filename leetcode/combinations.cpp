class Solution {
    public:
        vector<vector<int> > combine(int n, int k) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int> > results(0);
            listCombine (n, k, 1, results);
            return results;
        }
        void listCombine (int n, int remain, int index,
                vector<vector<int> > & results){
            if (index>n+1){
                return;
            }
            if (remain<0){
                return;
            }
            if (remain==0){
                vector<int> seed(0);
                results.push_back(seed);
                return;
            }
            listCombine (n, remain, index+1, results);
            vector<vector<int> > temp(0);
            swap (temp,results);
            listCombine (n, remain-1, index+1, results);
            for (int i=0; i<results.size(); ++i){
                results[i].insert(results[i].begin(), index);
            }
            results.insert(results.end(), temp.begin(), temp.end());
        }
};
