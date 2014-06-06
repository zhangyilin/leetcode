/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void bfs (TreeLinkNode* root){
        queue<TreeLinkNode*> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()){
            TreeLinkNode* cur = q.front();
            q.pop();
            if (cur){
                cur->next = q.front();
                if (cur->left)  q.push(cur->left);
                if (cur->right)  q.push(cur->right);
            }else{
                if (!q.empty()) q.push(NULL);
            }
        }
    }
    void connect(TreeLinkNode *root) {
        if (!root)  return;
        bfs(root);
    }
};
