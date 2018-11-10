class Solution {
    private:
        std::vector<int> treeNodeValStore;
        void preOrderTraversal(TreeNode* node, std::vector<int>& store){
            if(!node)
              return;
            preOrderTraversal(node->left,store); 
            preOrderTraversal(node->right,store); 
            store.push_back(node->val);
        }
            
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            preOrderTraversal(root,treeNodeValStore);
            return treeNodeValStore;
             
                
                
        
        
    }
};
