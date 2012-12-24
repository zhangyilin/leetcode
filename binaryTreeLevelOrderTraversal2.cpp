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
        vector<vector<int> > levelOrderBottom(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int> > output(0);
            if (root == NULL){
                return output;
            }
            queue<TreeNode *> q1;
            q1.push(root);
            queue<TreeNode *> q2;
            do{
                vector<int> v(0);
                while (!q1.empty()){
                    TreeNode* n = q1.front();
                    q1.pop();
                    v.push_back(n->val);
                    if (n->left) q2.push(n->left);
                    if (n->right) q2.push(n->right);
                }
                output.push_back(v);
                swap(q1,q2);
            }while (!q1.empty());
            reverse(output.begin(), output.end());
            return output;
        }
};
