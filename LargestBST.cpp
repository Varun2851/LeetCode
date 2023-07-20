class info{
public:
	bool isBst;
	int mn,mx,size;
};

class solution{
public:
	info solve(node*root){
		//base case
		if(!root){
			return {true,INT_MAX,INT_MIN,0};
		}

		if(!root->left and !root->right){
			return {true,root->val,root->val,1};
		}

		//recursive case

		info left = solve(root->left);
		info right = solve(root->right);
		info ans;

		if(left.isBst and right.isBst and root->val > left.mx and root->val <right.min){
			ans.mi = min(left.mi,min(right.mi,root->val));
			ans.mx = max(right.mx,max(left.mx,root->val));
			ans.size = 1+left.size+right.size;
			ans.isBst = true;
			return ans;
		}
		ans.isBst = false;
		ans.size = max(left.size,right.size);
		return ans;
	}

	int LargestBST(node*root){
		info ans = solve(root);
		return ans.size;
	}
}