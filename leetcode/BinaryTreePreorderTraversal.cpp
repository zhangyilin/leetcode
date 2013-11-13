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
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;
        if (!root)  return result;
        TreeNode* stop = root;
        do{
            if (stop->right){
                stop = stop->right;
            }else if (stop->left){
                stop = stop->left;
            }else{
                break;
            }
        }while (true);
        TreeNode* n = root;
        unordered_set<TreeNode*> visited;
        unordered_map<TreeNode*, TreeNode*> parents;
        do{
            if (visited.find(n)==visited.end()){
                result.push_back(n->val);
                visited.insert(n);
            }
            if (n->left && visited.find(n->left)==visited.end()){
                parents[n->left] = n;
                n = n->left;
            }else if (n->right && visited.find(n->right)==visited.end()){
                parents[n->right] = n;
                n = n->right;
            }else{
                if (parents.find(n)!=parents.end()){
                    n = parents[n];
                }
            }
        }while (visited.find(stop)==visited.end());
        return result;
    }
};
