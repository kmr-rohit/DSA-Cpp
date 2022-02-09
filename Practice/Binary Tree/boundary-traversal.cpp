/*'
We have to print the boundary traversal of a given tree,
For eg : 
           1 
         /   \
        2     7
      /        \ 
    3           8
     \         /
      4       9 
    /  \     / \ 
    5   6   10 11

    for this the anticlockwise boundary traversal :  1 2 3 4 5 6  10  11  9 8 7 
       
*/


#include <bits/stdc++.h>
using namespace std;

struct Node{
  public:
  int val;

  Node* left;
  Node* right;
  Node(int data){
    val = data;
    left = right = NULL;
  }

};

 bool isLeaf(Node* root) {
        return !root->left && !root->right;
    }

void leftboundary(Node* root , vector<int>res){
  Node* curr = root->left;
  while(curr){
  if(!isLeaf(curr)){res.push_back(curr->val);}
  if(!curr->left){
    curr = curr->left;
  }
  else{
    curr = curr->right;
  }
}
}
void leaves(Node*root , vector<int>res){
  if(isLeaf(root)){
    res.push_back(root->val);
    return;
  }
  if(root->left)leaves(root->left, res);
  if(root->right)leaves(root->right ,res);
 
}
void rightboundary(Node*root , vector<int> res){
  Node * curr = root->right;
  vector<int> temp; // for reversing elememts of right boundary we have to use another vector
  while(curr){
    if(!isLeaf(curr))temp.push_back(curr->val);
    if(curr->right)curr = curr->right;
    else curr = curr->left;

  }
  for(int i = temp.size()-1 ; i>=0 ; --i){
    res.push_back(temp[i]);

  }
}

vector<int>printBoundary(Node*root){
  vector<int> res;
  if(!isLeaf(root)){
    res.push_back(root->val);
  }
  leftboundary(root , res);
  leaves(root , res);
  rightboundary(root , res);
  for(int i = 0 ; i< res.size() ;i++ ){
    cout<<res[i]<<endl;
  }
  return res;
}
int main()
{
  Node * root = new Node(1);
  root->left  = new Node(2);
  root->left->left = new Node(3);
  root->left->left->right = new Node(4);
  root->left->left->right->left = new Node(5);
  root->left->left->right->right = new Node(6);
  root->right = new Node(7);
  root->right->right = new Node(8);
  root->right->right->left = new Node(9);
  root->right->right->left->left = new Node(10);
  root->right->right->left->right = new Node(11);
  printBoundary(root);
  
}