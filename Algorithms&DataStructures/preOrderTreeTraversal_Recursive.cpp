//Adapted from leetcode user gezi_shan
class Solution {
    private:
        std::vector<int> treeNodeValStore;
        void preOrderTraversal(TreeNode* node, std::vector<int>& store){
            if(!node)
              return;
            store.push_back(node->val);
            preOrderTraversal(node->left,store); 
            preOrderTraversal(node->right,store); 
        }
            
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            preOrderTraversal(root,treeNodeValStore);
            return treeNodeValStore;
             
                
                
        
        
    }
};
