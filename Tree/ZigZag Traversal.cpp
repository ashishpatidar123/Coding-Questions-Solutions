vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root) {
    
    // vector<vector<int>> ans;
    // if(root==NULL){
    //     return ans;
    // }
    // bool check = true;
    // TreeNode* temp = NULL;
    // queue<TreeNode*> q;
    // q.push(root);
    
    
    // while(!q.empty()){
        
    //     int size = q.size();
    //     vector<int> level(size);
        
    //     for(int i=0; i<size; i++){
            
    //         temp = q.front(); 
    //         q.pop();
            
    //         if(check==true){
    //             level[i] = temp->val;
    //         }
    //         else{
    //             level[size-i-1] = temp->val;
    //         }
            
    //         if(root->left!=NULL){
    //             q.push(root->left);
    //         }
    //         if(root->right!=NULL){
    //             q.push(root->right);
    //         }
    //     }
    //     check = !check;
        
    //     ans.push_back(level);
    // }
    // return ans;
    // intialise a count variable which helps us in deciding which order to follow
    int count=0;
    queue<TreeNode*>q;
    q.push(root);
    vector<vector<int>>ans;
    while(!q.empty()){
        int size=q.size();
        count++;
        vector<int>v;
        // traverse for all the nodes in the queue
        for(int i=0;i<size;i++){
            TreeNode* temp=q.front();
            // push the value into v
            v.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
           
            q.pop();
        }
        // now if count%2!=0 which means we will follow left to right order,
        // so we push v directly into our answer matrix
        if(count%2!=0){
            ans.push_back(v);
        }
        // if count%2==0 then we will follow right to left order
        // so we push v after reversing
        else{
            reverse(v.begin(),v.end());
            ans.push_back(v);
        }
       
       
    }
    return ans;
}
// second solutions

class Solution{
    private: 
    int height(Node*root){
        if(root==NULL){
            return 0;
        }
        else {
            int leftheight = height(root->left);
            int rightheight = height(root->right);
            
            return max(leftheight,rightheight)+1;
        }
    }
    void printZigZag(Node*root,int level, bool check, vector<int> &ans){
        if(root==0){
            return;
        }
        if(level==1){
            ans.push_back(root->data);
            return;
        }
        else{
            if(!check){
                printZigZag(root->right,level-1,check,ans);
                printZigZag(root->left,level-1,check,ans);
            }
            else{
                printZigZag(root->left,level-1,check,ans);
                printZigZag(root->right,level-1,check,ans);
            }
        }
    }
    void print(Node*root,vector<int> &ans){
        bool check = true;
        int h = height(root);
        
        for(int i=1; i<=h; i++){
            printZigZag(root,i,check,ans);
            check = !check;
        }
    }
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> ans;
    	print(root,ans);
    	return ans;
    }
};
