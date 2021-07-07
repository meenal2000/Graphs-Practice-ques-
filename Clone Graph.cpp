time - O(n+m)
space - O(n)
    
// u can do the same using bfs too

unordered_map<int,Node*> mp; // value and address of new node
Node* solve(Node* node)
{
    if(!node)
        return NULL;
    if(mp.find(node->val)!=mp.end())
        return mp[node->val];
    Node* tmp = new Node(node->val);
    mp[tmp->val] = tmp;
    for(Node* neigh : node->neighbors)
    {
        tmp->neighbors.push_back( solve(neigh) );
    }
    return tmp;
}
Node* cloneGraph(Node* node) {
    return solve(node);
}
