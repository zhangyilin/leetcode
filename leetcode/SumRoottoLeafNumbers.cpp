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
    int sumNumbers(TreeNode *root, int sum) {
        if (!root)  return 0;
        sum *= 10;
        sum += root->val;
        int down_sum = sumNumbers(root->left, sum)+sumNumbers(root->right, sum);
        return down_sum==0?sum:down_sum;
    }
    int sumNumbers(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        return sumNumbers (root, 0);
    }
};
