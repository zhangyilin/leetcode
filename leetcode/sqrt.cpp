class Solution {
  public:
    int sqrt(int x) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
      if (x <= 0) return 0;
      if (x == 1) return 1;
      int n = 0;
      int y = x;
      while (y != 1){ 
        n++;
        y >>= 1;
      }   
      int half_n = n/2;
      long long ans = pow(2.0, half_n);
      long long high = pow(2.0, half_n+1);
      long long low = pow(2.0, half_n);
      while (high-low > 1){ 
        long long square = ans*ans;        if (square > x){ 
          high = ans;
          ans = (low+high)/2;
        }else if (square == x){ 
          return ans;        }else{          low = ans;          ans = (low+high)/2;        }         }   
            for (ans=low; ans<=high; ++ans){        if (ans*ans > x) return ans-1;
      }   
      return high;
    }   
};
