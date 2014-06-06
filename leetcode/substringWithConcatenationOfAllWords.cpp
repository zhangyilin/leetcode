class Solution {
  public:
    vector<int> findSubstring(string S, vector<string> &L) {
      vector<int> result;
      if (L.empty())  return result;
      int step = L[0].size();
      int n = L.size();
      unordered_map<string,int> full_bag;
      for (int i=0; i<n; ++i){
        full_bag[L[i]]++;
      }
      for (int start=0; start<step; ++start){
        unordered_map<string,int> bag = full_bag;
        int left = start;
        for (int cur=start; left+(n-1)*step<S.size(); ){
          string word = S.substr(cur, step);
          if (full_bag.find(word) == full_bag.end()){
            bag = full_bag;
            left = cur+step;
          }else{
            bag[word] = bag.find(word)==bag.end()?-1:bag[word]-1;
            if (bag[word]==0)   bag.erase(word);
            if (bag.empty()){
              result.push_back(cur-(n-1)*step);
            }
            if (cur-left>(n-2)*step){
              string left_word = S.substr(left, step);
              left += step;
              bag[left_word]++;
              if (bag[left_word]==0)   bag.erase(left_word);
            }
          }
          cur += step;
        }
      }
      return result;
    }
};
