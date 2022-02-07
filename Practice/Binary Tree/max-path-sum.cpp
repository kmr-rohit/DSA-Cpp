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


int maxpath(Node* root, int& sum){
	if(root == NULL){
		return 0;
	}
	int leftsum = maxpath(root->left, sum);
	int rightsum = maxpath(root->right,sum);
  sum = max(sum , leftsum +rightsum + root->val);
  return root->val+max(leftsum , rightsum);
  
}
int maxpathsumOfBinaryTree(Node* root) {
      int sum = 0;
      maxpath(root, sum);
      cout<<sum<<endl;
      return sum;
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
  root->left->left->right->right =  new Node(5);
  
  maxpathsumOfBinaryTree(root);

}