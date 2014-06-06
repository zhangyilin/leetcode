class Solution {
  public:
    void reverseWord(string &word, int start, int end){
      int left = start;
      int right = end;
      while (left < right){
        swap (word[left], word[right]);
        ++left;
        --right;
      }
    }
    void reverseWords(string &s) {
      int n = s.size();
      reverseWord(s, 0, n-1);

      int right = -1;
      int left = 0;
      while (right < n && left < n){
        left = right+1;
        while (left < n && s[left] == ' '){
          ++left;
        }
        right = left;
        while (right < n && s[right] != ' '){
          ++right;
        }
        --right;
        reverseWord (s, left, right);
      }
      string ss;
      bool need_space = false;
      bool no_word_yet = true;
      for (right = 0; right < n; ++ right){
        if (s[right] != ' '){
          no_word_yet = false;
          if (need_space){
            ss += ' ';
          }
          need_space = false;
          ss += s[right];
        }else{
          if (!no_word_yet)
            need_space = true;
        }
      }
      s = ss;
    }
};
