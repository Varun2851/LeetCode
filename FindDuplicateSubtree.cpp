#define node TreeNode
class Solution {
public:
    string solve(node*root,unordered_map<string,int>&mp,vector<node*>&duplicate){
        //base case 
        if(!root){
            return "#";
        }

        string left = solve(root->left,mp,duplicate);
        string right = solve(root->right,mp,duplicate);

        string s = left+","+right+","+to_string(root->val);

        if(mp[s] == 1){
            duplicate.push_back(root);
        }
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>mp;
        vector<node*>duplicate;
        solve(root,mp,duplicate);
        return duplicate;
    }
};