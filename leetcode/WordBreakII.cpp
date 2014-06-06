class Solution {
  public:
    void backTracking (const string& s, vector<vector<int> >&prev, int index, vector<string>& output){
      for (int i=0; i<prev[index].size(); ++i){
        int prev_index = prev[index][i];
        vector<string> prev_output(0);
        if (prev_index != 0)
          backTracking (s, prev, prev_index, prev_output);
        else
          prev_output = vector<string> (1, "");
        for (int j=0; j<prev_output.size(); ++j){
          if (prev_index != 0)
            output.push_back(prev_output[j]+" "+s.substr(prev_index,index-prev_index));
          else
            output.push_back(s.substr(prev_index,index-prev_index));
        }   
      }        
    }   
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
      int n = s.size();
      if (n == 0) return vector<string> (0);
      vector<vector<int> > dp_prev(n+1, vector<int> (0));//dp_prev[k] has all the prev nodes for substr(0,k-1)
      dp_prev[0] = vector<int> (1,-1);//assign any number to it make it valid
      for (int i=1; i<n+1; ++i){
        for (int j=0; j<i; ++j){
          if (dp_prev[j].size()>0 && dict.find(s.substr(j,i-j))!=dict.end()){
            dp_prev[i].push_back(j);
          }   
        }   
      }   
      //backtracking
      vector<string> output(0);
      backTracking (s, dp_prev, n, output);
      return output;
    }   
};
