// time and space - O(n)
void solve(Node* root, int ord, vector<Node*> &prev)
    {
        if(!root)
            return;
        root -> nextRight = NULL;
        if(ord == prev.size())
        {
            prev.push_back(root);
        }
        else
        {
            prev[ord] -> nextRight = root;
            prev[ord] = root;
        }
        solve(root->left,ord+1,prev);
        solve(root->right,ord+1,prev);
    }
    void connect(Node *root)
    {
       vector<Node*> prev;
       solve(root , 0 , prev);
    }    
