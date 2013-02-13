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

vector<List<Node> > createLevelLinkedList(Node root){
    Queue currentQ;
    currentQ.push(&root);
    Queue nextQ;
    
    vector<List<node> > lists;
    while (!currentQ.empty()){
        List<node> list;
        while (!currentQ.empty()){
            Node * node = currentQ.top();
            currentQ.pop();
            if (!node) continue;
            list.add(node);//add double linked new element in list
            nextQ.push(node.left());
            nextQ.push(node.right());
        }
        currentQ = nextQ;
        lists.add(list);
    }
    return lists;

}
