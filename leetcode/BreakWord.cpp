class Solution {
  public:
    int min_word;
    bool dpWordBreak(const string& s, unordered_set<string> &dict, 
        unordered_map<string, bool > & dp) {//n>=1
      int n = s.size();
      
      if (n<min_word){
            return false;
      }
      if (dp.find(s) != dp.end()){
        return dp[s];
      }   
      if (dict.find(s) != dict.end()){
          dp[s] = true;
        return true;
      }   
      for (int left_len=1; left_len<=n-1; ++left_len){
        bool lresult = dpWordBreak (s.substr(0,left_len), dict, dp);
        if (!lresult)  {
            continue;
        }
        bool rresult = dpWordBreak (s.substr(left_len,n-left_len), dict, dp);
        if (!rresult)  {
            continue;
        }
        dp[s] = true;
        return true;  
      }
        dp[s] = false;
        return false;  
    }   
    bool wordBreak(string s, unordered_set<string> &dict) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
      if (s.size() == 0) {
        return false;
      }
      min_word = INT_MAX;
      for (unordered_set<string>::iterator it=dict.begin(); it!=dict.end(); ++it){
          min_word = min(min_word, (int)it->size());
      }
      unordered_map<string, bool> dp; 
      return dpWordBreak (s, dict, dp);
    }   
};
