class Solution {
public:
    bool dfs (const int& m, const int& n, const int& i, const int& j, const vector<vector<char> > &board, const string& word, vector<vector<bool> >& used){
        if (word.size() == 0)   return true;
        if (i<0 || i>=m || j<0 || j>=n) return false;
        if (used[i][j]) return false;
        if (board[i][j]!=word[0])   return false;
        used[i][j] = true;
        string new_word = word.substr(1);
        if ( dfs(m,n,i-1,j,board,new_word, used) )    return true;
        if ( dfs(m,n,i+1,j,board,new_word, used) )    return true;
        if ( dfs(m,n,i,j-1,board,new_word, used) )    return true;
        if ( dfs(m,n,i,j+1,board,new_word, used) )    return true;
        used[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = board.size();
        if (m == 0) return false;
        int n = board[0].size();
        vector<vector<bool> > white(m, vector<bool>(n,false));
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (dfs(m,n,i,j, board, word,white)){
                    return true;
                }    
            }
        }
        return false;
    }
};
