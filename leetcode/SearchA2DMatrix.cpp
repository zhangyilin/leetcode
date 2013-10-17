class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        int n = matrix[0].size();
        if (m<=0 || n<=0)   return false;
        int i=m-1;
        for (; i>=0; --i){
            if (matrix[i][0] == target) return true;
            if (matrix[i][0] < target) break;
        }
        if (i<0)    return false;
        for (int j=0; j<n; ++j){
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target) return false;
        }
        return false;
    }
};
