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

int main()
{
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  cout<<root->left->val;

  
}