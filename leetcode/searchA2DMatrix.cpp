class Solution {
  public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
      int row;
      for (row = 0; row < matrix.size(); ++ row){
        if (matrix[row][0] > target)    break;
      }
      row--;
      if (row < 0)    return false;
      for (int col = 0; col < matrix[row].size(); ++col){
        if (matrix[row][col] == target){
          return true;
        }else if (matrix[row][col] > target){
          return false;
        }
      }
      return false;
    }
};
