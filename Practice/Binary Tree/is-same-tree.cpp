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

bool issame(Node* p, Node* q) {
        if(p==NULL&&q==NULL){
          return true;
        }
          
        if(q==NULL&&p!=NULL){
          return false;
        }

          if(p==NULL&&q!=NULL){
            return false;

          }
            
          else{
            return (p->val == q->val) && issame(p->left , q->left) && issame(p->right , q->right);

          }
}
int main()
{
  Node* root1 = new Node(1);
  root1->left = new Node(2);
  root1->right = new Node(2);
  root1->left->left = new Node(3);
  root1->left->right = new Node(3);
  root1->left->left->left = new Node(4);
  root1->left->left->right = new Node(4);
  root1->left->left->right->right =  new Node(4);
  Node* root2 = new Node(1);
  root2->left = new Node(2);
  root2->right = new Node(2);
  root2->left->left = new Node(3);
  root2->left->right = new Node(3);
  root2->left->left->left = new Node(4);
  root2->left->left->right = new Node(4);
  root2->left->left->right->right =  new Node(4);
  cout<<issame(root1 , root2 );

}

