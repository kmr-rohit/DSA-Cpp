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
void preorder(Node* root){
  if(root == NULL){
    return;
  }
  cout<<root->val<<" ";
  preorder(root->left);
  preorder(root->right);

}
/*
we have a tree: 
                  1
              2      3
           4    5 6    7 
      

Acc to preorder traversel (root->left->right)
it should print : 1 2 4 5 3 6 7
*/
int main()
{
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  preorder(root);

  
 
}
