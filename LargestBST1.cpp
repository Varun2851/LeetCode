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
		if(left.isBst and right.isBst and root->val > left.mn and root->val <right.mx){

			ans.mn = min(left.mn,min(right.mn,root->val));
			ans.mx = max(right.mx,max(left.mx,root->val));
			ans.isBst = true;
			ans.size = 1+left.size+right.size;
			return ans;
		}
		ans.isBst = false;
		ans.size = max(left.size,right.size);
		return ans;
	}

	int largestBST(node*root){
		solve(root);
		return ans.size;
	}
}

