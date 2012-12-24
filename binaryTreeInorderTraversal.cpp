/*
   Use a stack to record unvisited nodes. The top one on the stack should be the one to visit next step.
   left_child_visit is used to identify if the left part of next poped node needs visit.
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
            vector<int> iot(0);//inorder traversal
            if (root == NULL){
                return iot;
            }
            stack<TreeNode*> stk;
            TreeNode * current = NULL;
            bool left_child_visited = false;
            stk.push(root);
            while (!stk.empty()){
                current = stk.top();
                stk.pop();
                if (current->left == NULL || left_child_visited){
                    iot.push_back(current->val);
                    if (current->right){
                        stk.push(current->right);
                        left_child_visited = false;
                    }else{
                        left_child_visited = true;
                    }

                }else{
                    stk.push(current);
                    stk.push(current->left);
                    left_child_visited = false;
                }
            }
            return iot;

        }
};
