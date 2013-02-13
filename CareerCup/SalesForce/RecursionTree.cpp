/*--------------BFS first--------------*/
/*--------------Not recursion, and forget linked list children-------------*/
void BFS(Node* root){
    queue<Node*> q;
    q.push_back(root);
    while (!q.empty()){
        Node* current = q.front();
        q.pop();
        if (!current)
            continue;
        current->visit();
        q.push_back(current->left);
        q.push_back(current->right);
    }

}
void DFS (Node* const root){
    if (!root)
        return;
    root->visit();
    for (const_iterator it = root->get_begin(); it != root->get_end(); ++it){
        DFS(it);
    }
}
