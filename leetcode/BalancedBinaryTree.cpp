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
    bool helper (TreeNode* root, int& hmax){
        if (!root){
            hmax=0;
            return true;
        }
        int lhmax, rhmax;
        bool lb = helper(root->left, lhmax);
        bool rb = helper(root->right, rhmax);
        hmax = 1+max(lhmax, rhmax);
        return (lb && rb && abs(lhmax-rhmax)<=1);
    }
    bool isBalanced(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root)  return true;
        int hmax;
        return helper(root, hmax);
    }   
};
