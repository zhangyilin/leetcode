class Solution {
    public:
        int romanToInt(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int n = s.length();
            int num=0;
            for (int i=0; i<n; ++i){
                char c = s[i];
                switch (c){
                    case 'M':
                        if (i>0 && s[i-1]=='C'){
                            num += 800;
                        }else{
                            num += 1000;
                        }
                        break;
                    case 'D':
                        if (i>0 && s[i-1]=='C'){
                            num += 300;
                        }else{
                            num += 500;
                        }
                        break;
                    case 'C':
                        if (i>0 && s[i-1]=='X'){
                            num += 80;
                        }else{
                            num += 100;
                        }
                        break;
                    case 'L':
                        if (i>0 && s[i-1]=='X'){
                            num += 30;
                        }else{
                            num += 50;
                        }
                        break;
                    case 'X':
                        if (i>0 && s[i-1]=='I'){
                            num += 8;
                        }else{
                            num += 10;
                        }
                        break;
                    case 'V':
                        if (i>0 && s[i-1]=='I'){
                            num += 3;
                        }else{
                            num += 5;
                        }
                        break;
                    case 'I':
                        num += 1;
                        break;
                }
            }
            return num;
        }
};
