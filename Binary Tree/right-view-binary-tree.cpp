/*
void recurRight(TreeNode* root , int level , vector<int> &res){
        if(root == NULL) return;
        if(res.size() == level)res.push_back(root->val);
        recurRight(root->right , level+1 , res);
        recurRight(root->left , level+1 , res);
        // switch upper 2 lines respect to needed view

    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res; 
        recurRight(root , 0, res);
        return res;
    }
*/