class Solution {
  public:
    bool isMatch(const char *s, const char *p) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      if (*s =='\0' && *p=='\0')  return true;
      if (*p=='\0') return false;
      if (*s=='\0'){
        while (*p!='\0'){
          if (*p != '*'){
            return false;
          }
          p++;
        }
        return true;
      }
      const char* ss=s;
      const char* pp=p;
      int n=0, np=0, nstar=0;
      while (*ss!='\0'){n++;ss++;}
      while (*pp!='\0'){
        if(*pp=='*')  nstar++;
        np++;pp++;
      }
      if (np-nstar>n) return false;
      const char* current_p;
      vector<bool> current (n, false);
      vector<bool> prev (n, false);
      bool p_empty = true;
      for (int i=0; i<np; ++i){
        current_p = p+i;
        if (*current_p == '?'){
          for (int j=0; j<n-1; ++j){
            if (prev[j] == true){
              current[j+1] = true;
            }   
          }   
          if (p_empty)  current[0] = true;
          p_empty = false;
        }else if (*current_p == '*'){
          for (int j=0; j<n; ++j){
            if (prev[j] == true){
              for (int k=j; k<n; ++k)
                current[k] = true;
            }   
          }
          if (i == 0){
            for (int j=0; j<n; ++j){
              current[j] = true;
            }
          }
          if (p_empty)  current[0] = true;
        }else{
          for (int j=0; j<n-1; ++j){
            if (prev[j] == true && s[j+1]==*current_p){
              current[j+1] = true;
            }   
          }   
          if (p_empty && *s==*current_p)  current[0] = true;
          p_empty = false;
        }   
        prev = current;
        current = vector<bool> (n, false);
      }
      return prev[n-1];

    }
};
