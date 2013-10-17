class Solution {
public:
    int numTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > dp(n, vector<int>(n,0));
        for (int i=0; i<n; ++i){
            dp[i][i] = 1;
        }
        for (int len=2; len<=n; ++len){
            for (int start=0; start<=n-len; ++start){
                for (int root=start; root<=start+len-1; ++root){
                    if (root==start){
                        dp[start][start+len-1] += dp[root+1][start+len-1];
                    }else if (root==start+len-1){
                        dp[start][start+len-1] += dp[start][root-1];
                    }else{
                        dp[start][start+len-1] += dp[start][root-1]*dp[root+1][start+len-1];
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};
