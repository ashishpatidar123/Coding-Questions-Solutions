vector<int> solve(binaryTreeNode*root, int key){
	int pred = -1;
	int succ = -1;
  binaryTreeNode* temp = root;
  // find the node 
  // while traversing store the possible succ and pred 
  // because it may happen that there is not left subtree so predecessor will be any ancestor
	while(temp->data!=key){
		if(temp->data>key){
			succ = temp->data;
			temp = temp->left;
		}
		else{
			pred = temp->data;
			temp = temp->right;
		}
	}
  // now find the maximum element in the right half
	binaryTreeNode* leftTree = temp->left;

	while(leftTree!=NULL){
		pred = leftTree->data;
		leftTree = leftTree->right;
	}
 // find the minimum element in the left half
	binaryTreeNode* rightTree = temp->right;

	while(rightTree!=NULL){
		succ = rightTree->data;
		rightTree = rightTree->left;
	}
	vector<int> ans(2,0);
	ans[0] = pred;
	ans[1] = succ;
	return ans;
}
vector<int> findPreSuc(binaryTreeNode *root, int key)
{   
	vector<int> ans;
	if(root==NULL){
		return ans;
	}
	return solve(root,key);
}
