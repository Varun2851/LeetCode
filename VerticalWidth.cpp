#define node Node
int levelOrder(node*root){
    if(root == NULL){
        return 0;
    }
    int maxlen = INT_MIN;
    int minlen = INT_MAX;
    queue<pair<node*,int>>q;
    q.push({root,0});
    
    while(!q.empty()){
        int size = q.size();
        
        for(int i = 0; i<size; i++){
            auto X = q.front();
            q.pop();
            
            auto first = X.first;
            auto second = X.second;
            
            if(first->left){
                minlen = min(minlen,second-1);
                q.push({first->left,second-1});
            }
            
            if(first->right){
                maxlen = max(maxlen,second+1);
                q.push({first->right,second+1});
            }
        }
    }
    
    return abs(minlen)+maxlen+1;
}
int verticalWidth(Node* root)
{
    // Code here
    
    int ans = levelOrder(root);
    return ans;
}