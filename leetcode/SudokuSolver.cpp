class Solution {
public:
    pair<int,int> findFirstEmpty(const vector<vector<char> > & board){
        int n = board.size();
        for (int i=0; i<n; ++i){
            for (int j=0; j<n; ++j){
                if (board[i][j]=='.')   return pair<int,int> (i,j);
            }
        }
        return pair<int,int> (-1,-1);
    }
    bool isValid (const vector<vector<char> > & board, pair<int, int> pos){
        int n = board.size();
        int i=pos.first;
        int j=pos.second;
        char v = board[i][j];
        for (int k=0; k<n; ++k){//horizontal line
            if (k == j) continue;
            if (board[i][k] == v)   return false;
        }
        for (int k=0; k<n; ++k){//horizontal line
            if (k == i) continue;
            if (board[k][j] == v)   return false;
        }
        for (int ii=(i/3)*3; ii<(i/3)*3+3; ++ii){
            for (int jj=(j/3)*3; jj<(j/3)*3+3; ++jj){
                if (ii==i && jj==j) continue;
                if (board[ii][jj] == v)   return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        solveSudoku2 (board);
    }
    bool solveSudoku2(vector<vector<char> > &board) {
        int n = board.size();
        pair<int, int> pos = findFirstEmpty(board);
        if (pos.first == -1)    return true;
        for (int i=1; i<=9; ++i){
            board[pos.first][pos.second] = '0' + i;
            if (isValid(board, pos) && solveSudoku2 (board)){
                return true;
            }else{
                board[pos.first][pos.second] = '.';
            }
        }
        return false;
    }
};
