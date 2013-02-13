#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int getLength (TreeNode root){
    if (!root)  return 0;
    return max(getLength(root.left), getLength(root.right)) + 1;
}
bool isBalanced (TreeNode root){
    if (!root)
        return true;
    if (!isBalanced(root.left) || !isBalanced(root.rightchild))  return false;
    int leftLength = getLength(root.left);
    int rightLength = getLength(root.rightchild);
    return abs(leftLength - rightLength)<=1;
}
