class info{
public:
	bool isBST;
	int mn,mx,size;
};
class solution{
public:
	info solve(node*root){
		//base case
		if(!root){
			return {true,INT_MAX,INT_MIN,,0};
		}

		if(!root->left and !root->right){
			return {true,root->val,root->val,1};
		}

		//recursive case
		info left = solve(root->left);
		info right = solve(root->right);
		info ans;

		if(left.isBST and right.isBST and root->val > left.mx and root->val < right.mn){
			ans.mn = min(left.mn,min(right.mn,root->val));
			ans.mx = max(right.mx,max(left.mx,root->val));
			ans.isBST = true;
			ans.size = 1+left.size+right.size;
			return ans;
		}
		ans.isBST = false;
		ans.size = max(left.size,right.size);
		return ans;
	}

	int LargestBST(node*root){
		solve(root);
		return ans.size;
	}
}