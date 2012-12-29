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
        TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int n = inorder.size();
            if (n <= 0){ 
                return NULL;
            }
            return buildTreeByIndex (inorder, postorder, 0, n-1, 0, n-1);

        }   
        TreeNode *buildTreeByIndex (vector<int> &inorder, vector<int> &postorder, 
                int in1, int in2, int post1, int post2){
            if (in1 > in2){
                return NULL;
            }   

            int root = postorder[post2];
            int index = find(inorder.begin()+in1, inorder.begin()+in2, root) - inorder.begin();

            TreeNode * pleft = buildTreeByIndex (inorder, postorder, in1, index-1, post1, post1+index-1-in1);
            TreeNode * pright = buildTreeByIndex (inorder, postorder, index+1, in2, post1+index-in1, post2-1);
            TreeNode *proot = new struct TreeNode (root);
            proot->left = pleft;
            proot->right = pright;
            return proot;
        }
};
int main(){
    int in [] = {2,1};
    vector<int> in1(in, in + sizeof(in)/sizeof(int));
    int post [] = {2,1};
    vector<int> post1(post, post + sizeof(post)/sizeof(int));
    Solution s;
    s.buildTree (in1, post1);
}
