#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
};
Node* print(Node * head){
  while(head->next != NULL){
    cout<<head->data<<" ";
    head = head->next;
  }

}

int main(){
  Node* dummy = new Node();
  Node* head = dummy;

  while(true){
    
    int i;
    cin>>i;
    if( i == -1){
      break;
    }
    dummy->data = i;
    dummy->next = new Node();
    dummy = dummy->next;
    
  }

  print(head);


}