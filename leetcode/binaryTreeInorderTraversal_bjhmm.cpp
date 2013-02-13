/*
   bjhmm version. Looks simple and extendable.
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
        vector<int> inorderTraversal(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> iot(0);
            stack<TreeNode*> stk;
            TreeNode* current = root;
            while (current || !stk.empty()){
                while (current){
                    stk.push(current);
                    current = current->left;
                }
                if (!stk.empty()){
                    current = stk.top();
                    stk.pop();
                    iot.push_back(current->val);
                    current = current->right;
                }

            }
            return iot;
        }
};
