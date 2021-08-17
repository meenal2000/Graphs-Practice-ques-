// complexity analysis
// time - O(n)
// space - O(height of the tree)
int solve( Node* root, bool order )
    {
        if(!root)
            return 0;
        if(order)
        {
            int s1 = root->data +solve(root->left,0)+solve(root->right,0);
            int s2 = solve(root->left,1)+solve(root->right,1);
            return max(s1,s2);
        }
        else
        {
            return solve(root->left,1)+solve(root->right,1);
        }
    }
    int getMaxSum(Node *root) 
    {
        bool order = 1; // we consider that node
        return solve(root,order);
    }
