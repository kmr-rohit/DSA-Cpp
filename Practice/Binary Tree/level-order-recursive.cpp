/* Level Order Traversal of a given binary tree 
  For Example : 
   Input:     2
            /  \
          3     4
        /  \   /  \ 
      5    6  7    8 

    Output : 2 3 4 5 6 7 8

  Approach : Recursive

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
int height(Node* root){
	if(root == NULL){
		return 0;
	}

else{
	int leftheight = height(root->left);
	int rightheight = height(root->right);

	if(leftheight>rightheight){
		return leftheight +1;
	}
	else{
		return rightheight + 1;
	}
}
}
void processlevel(Node * root , int l){
	if (root == NULL){
		return ;
	}
	if(l == 0){
		cout<<root->data<< " ";

	}
	else if(l>0){
		processlevel(root->left , l-1);
		processlevel(root->right , l-1);

	}
}
void levelorder(Node* root ){
	int h = height(root);
	for(int l = 0 ; l< h ; l++){
		processlevel(root ,l);
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

}