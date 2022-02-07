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

int height(Node* root, int& diameter){
	if(root == NULL){
		return 0;
	}
	int leftheight = height(root->left, diameter);
	int rightheight = height(root->right,diameter);
  diameter = max(diameter , leftheight+rightheight);
  return 1+max(leftheight , rightheight);
  
}
int diameterOfBinaryTree(Node* root) {
      int diameter = 0;
      height(root, diameter);
      cout<<diameter<<endl;
      return diameter;
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
  root->left->left->right->right =  new Node(4);
  int diameter = 0;
  diameterOfBinaryTree(root);



 
}
