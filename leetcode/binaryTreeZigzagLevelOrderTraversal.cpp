/*
   very similar to level-by-level print
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int> > vvi;
            if (root==NULL){
                return vvi;
            }
            vector<int> vi;
            queue<TreeNode*> q, next_q;
            q.push(root);
            bool odd = true;
            while (!q.empty()){
                TreeNode* n = q.front();
                q.pop();
                vi.push_back(n->val);
                if (n->left){
                    next_q.push(n->left);
                }
                if (n->right){
                    next_q.push(n->right);
                }
                if (q.empty()){
                    if (!odd){
                        reverse (vi.begin(), vi.end());
                    }
                    vvi.push_back(vi);
                    vi.clear();
                    odd = !odd;
                    swap (q,next_q);
                }
            }
        }
};
