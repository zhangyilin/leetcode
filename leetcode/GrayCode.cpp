class Solution {
  public:
    vector<int> grayCode(int n) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      // grayCode(n+1) = grayCode(n) + reverse(2^n+grayCode(n))
      if (n==0){
        vector<int> result(1,0);
        return result;
      }
      else if (n==1){
        vector<int> result;
        result.push_back(0);
        result.push_back(1);
        return result;
      }else{
        vector<int> sub = grayCode(n-1);
        vector<int> result = sub;
        int k = n-1;
        int offset = 1;
        while (k>0){
          offset = offset << 1;
          k--;
        }
        for (int i=sub.size()-1; i>=0;--i){
          result.push_back(sub[i]+offset);
        }
        return result;
      }


    }
};
