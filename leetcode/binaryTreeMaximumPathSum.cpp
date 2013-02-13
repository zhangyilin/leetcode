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
        void postOrderTraversal(TreeNode * root, queue<TreeNode*> & q){
            if (root == NULL)   return;
            postOrderTraversal (root->left, q);
            postOrderTraversal (root->right, q);
            q.push(root);
        }

            int maxPathSum(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if (root==NULL) return 0;
            queue<TreeNode*> q;
            postOrderTraversal (root, q);
            int max_sum = -INT_MAX;
            map <TreeNode*, int> m;//Record max path sum, which has one end at the key node
            while (!q.empty()){
                TreeNode * n = q.front();
                q.pop();
                if (!n->left && !n->right){//leaf
                    m[n] = n->val;
                    max_sum = max(max_sum, m[n]);
                }else{
                    int left_sum = 0, right_sum = 0;
                    if (n->left){
                        left_sum = max(m[n->left], 0);
                    }
                    if (n->right){
                        right_sum = max(m[n->right], 0);
                    }
                    m[n] = n->val + max(left_sum, right_sum);
                    max_sum = max(max_sum, n->val + left_sum + right_sum);
                }

            }
            return max_sum;

        }
};
