/* Level Order Traversal of a given binary tree 
  For Example : 
   Input:     1
            /  \
          2     3
        /  \   /  \ 
      4    5  6    7 

    Output : [[1] , [2 ,3] , [4,5,6,]]

  Approach : Idea is to use 2 queue's one to store root val and other to store its childern val;
              Iterate over fist q and append all elements of queue to ans list , then append q1 with all 
              element of q2, empty q2 , retitrate the same 

Code Solution: 
*/

#include <bits/stdc++.h>
using namespace std;
//Constuct Node
struct Node{
  public:
  int data;
  Node* left;
  Node* right;
  Node(int val){
    data = val;
    left = right =NULL;
  }
};

void levelorder(Node * root){
  if(root == NULL){
    return;
  }

  queue<Node*> Q;
  Q.push(root);

  while(Q.empty() == false){
    Node* temp = Q.front();
    cout<<temp->data<<" ";
    Q.pop();

    if(temp->left !=  NULL){
      Q.push(temp->left);

    }

    if(temp->right != nullptr){
      Q.push(temp->right);
    }
  }
}






int main()
{
  Node* root = new Node(2);
  root->left = new Node(3);
  root->right = new Node(4);
  root->left->left = new Node(5);
  root->left->right = new Node(6);
  root->right->left = new Node(7);
  root->right->right = new Node(8);
  levelorder(root);
  return 0;

}