class Solution {
  public:
    long long factorial (int n){
      assert (n>=0);
      if (n==0)   return 1;
      return n*factorial(n-1);
    }
    string getPermutation(int n, int k) {
      list<int> l;
      for (int i=1; i<=n; ++i){
        l.push_back(i);
      }
      return getPermutationSet (n, k, l);
    }
    string getPermutationSet(int n, int k, list<int> remains){
      if (n == 0) return "";
      long long fac = factorial(n-1);
      int index = (k-1)/fac + 1;
      list<int>::iterator it = remains.begin();
      for (int i=1; i<index; ++i){
        ++it;
      }
      char first = *it + '0';
      remains.erase(it);
      return first + getPermutationSet (n-1, k-fac*(index-1), remains);
    }
};
