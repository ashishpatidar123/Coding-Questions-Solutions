class Solution {
private:
    bool ismirror(TreeNode*A, TreeNode* B){
        if(A==NULL && B==NULL){
            return 1;
        }
        if(A==NULL || B==NULL){
            return 0;
        }

        return (A->val==B->val && ismirror(A->left,B->left)
                    && ismirror(A->right,B->right));
}
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return ismirror(p,q);
    }
};
