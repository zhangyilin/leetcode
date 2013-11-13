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
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;
        if (!root)  {
            return result;
        }
        TreeNode* n = root;
        unordered_map<TreeNode*,TreeNode*> parents;//key child, value parent
        unordered_set<TreeNode*> visited;
        do {
            if (n->left && visited.find(n->left)==visited.end()){
                parents[n->left] = n;
                n = n->left;
            }else if (n->right && visited.find(n->right)==visited.end()){
                parents[n->right] = n;
                n = n->right;
            }else{
                result.push_back(n->val);
                visited.insert(n);
                if (parents.find(n)!=parents.end()){
                    TreeNode* p = parents[n];
                    parents.erase(n);
                    n = p;
                }
            }
        }while (visited.find(root)==visited.end());
        return result;
    }
};
