/* Write a function to search the given element in a Single Linked List (SLL).
  Example: 
  Given SLL = 3->5->16->NULL
        search(14) : False 
        search(5) = True

 */

#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data; 
  Node * next;
};
// Given Boilerplate 

void push(Node**head_ref , int val){
  // Fisrt allocate a new node 
  Node*new_node = new Node();
  //setting a val to data 
  new_node->data = val;
  //adding node in ll
  new_node->next = (*head_ref);
  //making new node as head
  (*head_ref) = new_node;

}
//complete search function.
bool search(Node*head , int val){
  // basic idea is to iterate through the linked list until we find the given key  
  // for that we need a pointer to traverse the LL
  // let us create a pointer temp 
  Node * temp = head;

  // if ll is empty 
  if(temp == NULL){
    return false;
  }

  while(temp != NULL) 
  {
    if(temp->data == val ){
      return true;
    }
    else{
      temp = temp->next;
    }
  }
  


}

int main(){
  /* Start with the empty list */
    Node* head = NULL;
    int x = 21;
 
    /* Use push() to construct below list
    14->21->11->30->10 */
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);
 
    search(head, 21)? cout<<"Yes" : cout<<"No";
    
    return 0;
}


