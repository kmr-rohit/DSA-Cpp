/* zigzag Traversal of a given binary tree 
  For Example : 
   Input:     2
            /  \
          3     4
        /  \   /  \ 
      5     6 7    8 

    Output : [[1] , [3,2] , [5,6,7,8]]

  Approach : we will use a bool flag for telling us how we have to print , change index accordingly.

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

vector<vector<int>> zigzagtraversal(Node * root){
  vector<vector<int>> result;
  if(root == NULL){
    return result;
  }
  queue<Node*> q;
  q.push(root);
  bool leffToright = true;
  while(!q.empty()){
    int size = q.size();
    vector<int> row(size);
    for(int i = 0; i<size ; i++ ){
      Node* temp = q.front();
      q.pop();
      int index  = (leffToright)? i : (size -1- i);
      row[index] = temp->data;
      if(temp->left){
        q.push(temp->left);

      }
      if(temp->right){
        q.push(temp->right);

      }
    }
    leffToright = !leffToright;
    result.push_back(row);
  }
  for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
  return result;

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
  zigzagtraversal(root);
  return 0;

}