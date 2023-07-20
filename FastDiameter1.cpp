class Pair{
public:
	int height;
	int diameter;
};

Pair solve(node*root){
	Pair p;

	if(!root){
		p.height = p.diameter = 0;
		return p;
	}
	//recursive case
	Pair left = solve(root->left);
	Pair right = solve(root->right);

	p.height = max(left.height,right.height)+1;
	int op1 = left.diameter;
	int op2 = right.diameter;
	int op3 = left.height+right.height;

	p.diameter = max(op1,max(op2,op3));

	return p;
}