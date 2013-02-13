#include <iostream>
#include <vector>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
    public:
        TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int n = preorder.size();
            return helper (preorder, inorder, 0, n-1, 0, n-1);
        }
        TreeNode *helper (const vector<int> &preorder, const vector<int> &inorder, 
                int pre1, int pre2, int in1, int in2){
            if (pre1>pre2){
                return NULL;
            }
            int root = preorder[pre1];
            int index = find (inorder.begin()+in1, inorder.begin()+in2, root) - inorder.begin();
            TreeNode *pleft = helper (preorder, inorder, pre1+1, pre1+index-in1, in1, index-1);
            TreeNode *pright = helper (preorder, inorder, pre1+index-in1+1, pre2, index+1, in2);
            TreeNode *proot = new struct TreeNode(root);
            proot->left = pleft;
            proot->right = pright;
            return proot;
        }
};
int main(){
    int pre [] = {1,2};
    vector<int> pre1(pre, pre + sizeof(pre)/sizeof(int));
    int in [] = {2,1};
    vector<int> in1(in, in + sizeof(in)/sizeof(int));
    Solution s;
    s.buildTree (pre1, in1);
}
