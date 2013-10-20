/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *start, map<UndirectedGraphNode*, UndirectedGraphNode*>& m){
        if (start == NULL)  return NULL;
        UndirectedGraphNode* new_start;
        if (m.find(start) != m.end()){
            return m[start];
        }else {
            new_start = new UndirectedGraphNode(start->label);
            m[start] = new_start;
        }
        for (int i=0; i<start->neighbors.size(); ++i){
            UndirectedGraphNode* new_neighbor = cloneGraph(start->neighbors[i], m);
            new_start->neighbors.push_back(new_neighbor);
        }
        return new_start;
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        return cloneGraph(node, m);
    }
};
