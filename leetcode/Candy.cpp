class Solution {
  public:
    bool isHole (const vector<int>& ratings, int index){
      if (index>0 && ratings[index-1]<=ratings[index])    return false;
      if (index<ratings.size()-1 && ratings[index+1]<=ratings[index])    return false;
      return true;
    }   
    int candy(vector<int> &ratings) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
      int n = ratings.size();
      if (n == 0)    return 0;

      vector<int> candy(n, 0); 
      for (int i=0; i<n; ++i){
        if (isHole (ratings, i)){
          candy[i] = 1;
          for (int j=i-1; j>=0; --j){
            if (candy[j] == candy[j+1]){
              break;
            }   
            if (candy[j] != 0 && ratings[j]>ratings[j+1]){
              candy[j] = max(candy[j], candy[j+1]+1);
              break;
            }   
            candy[j] = candy[j+1]+1;
          }   
          for (int j=i+1; j<n; ++j){
            if (ratings[j]>ratings[j-1]){
              candy[j] = candy[j-1]+1;
            }else{
              break;
            }   
          }   
        }   
      }   
      int total=0;
      for (int i=0; i<n; ++i){
        cout << candy[i]<<endl;
        total += candy[i]==0?1:candy[i];//0 means same rating with neighbor
      }   
      return total;
    }   
};
