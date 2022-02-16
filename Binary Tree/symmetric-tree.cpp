leetcode problem : 101

solution: 

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root == NULL || isSymmetrichelp(root->left , root->right);
    }
    bool isSymmetrichelp(TreeNode* left , TreeNode* right){
        if(left == NULL || right == NULL ){
            return left == right;

        }
        if(left->val != right->val){
            return false;
        }

        return isSymmetrichelp(left->left , right->right) && isSymmetrichelp(left->right , right->left);
        
    }
};