/*  PreOrder Traversal of a given binary tree 
  For Example : 
   Input:     2
            /  \
          3     4
        /  \   /  \ 
      5    6  7    8 

    Output : 2 3 4 5 6 7 8

  Approach : Itertive

Code Solution: 
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
  public:
  int data;
  Node * left;
  Node * right;
  Node(int val){
    data = val;
    left = right = NULL;

  }

};

void iterativepreorder(Node* root){
  if(root == NULL){
    return;
  }
  Node* current_node;
  stack<Node*> remember;
  remember.push(root);
  while(remember.empty() == false){
    


  }

}

int main(){

  Node* root = new Node(2);
  root->left = new Node(3);
  root->right = new Node(4);
  root->left->left = new Node(5);
  root->left->right = new Node(6);
  root->right->left = new Node(7);
  root->right->right = new Node(8);
  
}
