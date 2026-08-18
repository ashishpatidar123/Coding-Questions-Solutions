class Solution {
  private:
    int countNodes(Node*tree){
        if(tree==NULL){
            return 0;
        }
        return 1+countNodes(tree->left)+countNodes(tree->right);
    }
  private: 
    bool CBT(Node*tree,int index,int total){
        if(tree==NULL){
            return true;
        }
        if(index>=total){
            return false;
        }
        else{
            return CBT(tree->left,2*index+1,total)&&CBT(tree->right,2*index+2,total);
        }
    }
  private: 
    bool isMaxheap(Node*tree){
        
        if(tree->right==NULL && tree->left==NULL){
            return true;
        }
        if(tree->right==NULL){
            return (tree->data > tree->left->data);
        }
        
        else{
            bool leftans =  isMaxheap(tree->left);
            bool rightans =  isMaxheap(tree->right);
            return tree->data>tree->left->data && tree->data > tree->right->data &&
                       isMaxheap(tree->left) && isMaxheap(tree->right);
        }
        
    }
  public:
    bool isHeap(struct Node* tree) {
        
        int index = 0;
        int total = countNodes(tree);
        if(CBT(tree,index,total)){
            return isMaxheap(tree);
        }
        return false;
    }
};
