class Solution {
    public:
        string addBinary(string a, string b) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int na = a.length();
            int nb = b.length();
            if (na > nb){//a will be the shorter string
                swap (a,b);
                swap (na,nb);
            }
            int carry = 0;
            string c("");
            for (int i = 0; i < nb; ++i){
                int a_bit = i<na?a[na-1-i]-'0':0;
                int b_bit = b[nb-1-i]-'0';
                int c_bit = (a_bit+b_bit+carry) % 2;
                carry = (a_bit+b_bit+carry)>>1;
                c = (char)(c_bit+'0') + c;
            }
            if (carry){
                c = '1' + c;
            }
            return c;
        }
};
