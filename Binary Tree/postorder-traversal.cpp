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
void postorder(Node* root){
  if(root == NULL){
    return;
  }
  
  postorder(root->left);
  postorder(root->right);
  cout<<root->val<<" ";

}
/*
we have a tree: 
                  1
              2      3
           4    5 6    7 
      

Acc to postorder traversel (left->right->root)
it should print : 4 5 2 6 7 3 1
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
  postorder(root);

  
 
}
