class Solution {
    private:
        std::vector<int> treeNodeValStore;
        void preOrderTraversal(TreeNode* node, std::vector<int>& store){
            if(!node)
              return;
            preOrderTraversal(node->left,store); 
            store.push_back(node->val);
            preOrderTraversal(node->right,store); 
        }
            
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            preOrderTraversal(root,treeNodeValStore);
            return treeNodeValStore;
             
                
                
        
        
    }
};
