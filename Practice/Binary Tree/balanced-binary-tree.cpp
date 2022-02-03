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
int dfsHeight (Node *root) {
        if (root == NULL) return 0;
        
        int leftHeight = dfsHeight (root -> left);
        if (leftHeight == -1) return -1;
        int rightHeight = dfsHeight (root -> right);
        if (rightHeight == -1) return -1;
        
        if (abs(leftHeight - rightHeight) > 1)  return -1;
        return max (leftHeight, rightHeight) + 1;
    }   
void isBalanced(Node* root) {
        if(dfsHeight(root) != -1){
          cout<<"True"<<endl;
        }
        else{
          cout<<"False"<<endl;
        }
    }
 
int main()
{
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(2);
  root->left->left = new Node(3);
  root->left->right = new Node(3);
 root->left->left->left = new Node(4);
 root->left->left->right = new Node(4);
 isBalanced(root);
}