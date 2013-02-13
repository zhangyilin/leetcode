class Solution {
    public:
        string convert(string s, int nRows) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function    
            if (nRows==1){
                return s;
            }
            vector<string> vs(nRows, "");
            int row_index=0;
            bool go_down=true;
            for (int i=0; i<s.size(); ++i){
                vs[row_index] += s[i];
                if (go_down){
                    if (row_index == nRows-1){
                        go_down = false;
                        row_index--;
                    }else{
                        row_index++;
                    }
                }else{
                    if (row_index == 0){
                        go_down = true;
                        row_index++;
                    }else{
                        row_index--;
                    }
                }
            }
            string final;
            for (int i=0; i<nRows; ++i){
                final += vs[i];
            }
            return final;
        }
};
