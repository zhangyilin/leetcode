class Solution {
  public:
    void reverse (string& s1){
      string s2; 
      for (int i=s1.length()-1; i>=0; --i){
        s2 += s1[i];
      }   
      s1 = s2; 
    }   
    void add (string& s1, string& s2, int s2_offset){
      int n1 = s1.length();
      int n2 = s2.length();
      reverse(s1);
      reverse(s2);
      string result;
      int carry = 0;
      for (int i=0; i<max(n1, n2+s2_offset); ++i){
        int sum = carry;
        if (i>=s2_offset && i<n2+s2_offset){
          sum += s2[i-s2_offset]-'0';
        }   
        if (i<n1){
          sum += s1[i]-'0';
        }   
        carry = sum>9?1:0;
        sum = sum%10;
        result += (sum+'0');
      }   
      if (carry)
        result += '1';
      reverse(result);
      s1 = result;
    }   
    string singleMultiply (string s, char c){
        if (c == '0')   return "0";
        int k = c - '0';
        reverse(s);
        string result;
        int carry = 0;
        for (int i=0; i<s.length(); ++i){
            int sum = carry;
            sum += k*(s[i]-'0');
            carry = sum/10;
            sum = sum%10;
            result += (sum+'0');
        }   
        if (carry)
            result += carry+'0';
        reverse(result);
        return result;
    }
    string multiply(string num1, string num2) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
      int n1 = num1.length();
      int n2 = num2.length();
      if (n1==0 || n2==0) return "0";
      string result = "0";
      for (int p2=n2-1; p2>=0; --p2){
        char c = num2[p2];
        string single = singleMultiply (num1, c);
        if (single == "0")  continue;
        add (result, single, n2-p2-1);
      }
      return result;
    }
};
