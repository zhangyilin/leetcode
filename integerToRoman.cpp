class Solution {
public:
    string bitToRoman(int bit, string one, string five, string ten){
        string s = "";
        switch (bit){
        case 1:
            s=one;
            break;
        case 2:
            s=one+one;
            break;
        case 3:
            s=one+one+one;
            break;
        case 4:
            s=one+five;
            break;
        case 5:
            s=five;
            break;
        case 6:
            s=five+one;
            break;
        case 7:
            s=five+one+one;
            break;
        case 8:
            s=five+one+one+one;
            break;
        case 9: 
            s=one+ten;
            break;
        }    
        return s;
            
    }
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function   
        int bit_1 = num%10;
        int bit_2 = (num/10)%10;
        int bit_3 = (num/100)%10;
        int bit_4 = (num/1000)%10;
        string s;
        if (bit_1 > 0){
            string s_1 = bitToRoman(bit_1, "I","V","X");
            s = s_1 + s;
        }
        if (bit_2 > 0){
            string s_2 = bitToRoman(bit_2, "X","L","C");
            s = s_2 + s;
        }
        if (bit_3 > 0){
            string s_3 = bitToRoman(bit_3, "C","D","M");
            s = s_3 + s;
        }
        if (bit_4 > 0){
            string s_4 = bitToRoman(bit_4, "M","","");
            s = s_4 + s;
        }
        return s;
    }
};
