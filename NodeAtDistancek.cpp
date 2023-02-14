#define node TreeNode
#define data val
class Solution {
public:
    vector<int>ans;
    void PrintatlevelK(node*root,int k){
        //base case
        if(!root){
            return;
        }
        if(k == 0){
            ans.push_back(root->data);
            return;
        }
        PrintatlevelK(root->left,k-1);
        PrintatlevelK(root->right,k-1);
    }
    int PrintatDistanceK(node*root,node*target,int k){
        if(!root){
            return -1;
        }
        if(root == target){
            PrintatlevelK(root,k);
            return 0;
        }

        int Dl = PrintatDistanceK(root->left,target,k);
        if(Dl != -1){
            //left m target exist krta h
            if(Dl+1 == k){
                ans.push_back(root->data);
            }
            else{
                PrintatlevelK(root->right,k-Dl-2);
            }
            return Dl+1;
        }
        int Dr = PrintatDistanceK(root->right,target,k);
        if(Dr != -1){
            if(Dr+1 == k){
                ans.push_back(root->data);
            }
            else{
                PrintatlevelK(root->left,k-Dr-2);
            }
            return Dr+1;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        PrintatDistanceK(root,target,k);
        return ans;   
    }
};