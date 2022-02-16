/* Given a singly linked list, find the middle of the linked list.
 For example, if the given linked list is 1->2->3->4->5 then the output should be 3. 
If there are even nodes, then there would be two middle nodes, we need to print the second middle element.
 For example, if given linked list is 1->2->3->4->5->6 then the output should be 4. 
*/

/*2 ways to solve the given problem: 
  1. Basic idea : traverse ll fully and count the no of nodes then find the middle node no 
  and acess that by traversing again 
  2. Use Of 2 pointers: use fast and slow pointers move fast twice as slow move. When fast reach the end of linked list 
    slow pointer will be at the middle of LL 
*/
// Lets see 2nd method code 

#include<bits/stdc++.h>
using namespace std;


class Node{
  public: 
  int data;
  Node* next;

};

void push(Node** head_ref, int new_data){

    /* 1. allocate node */
    Node* new_node = new Node();
 
    /* 2. put in the data */
    new_node->data = new_data;
 
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
 
    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}

void findmiddle(Node* head ){
  Node* slow = head;
  Node* fast = head; 
  if(head!= NULL){
    while(fast->next != NULL){
      fast = fast->next->next ;
      slow = slow->next; 
      

    }
    cout<<(slow->data)<<endl;
  }
}

  
int main(){
  Node *head = NULL;
  for(int i=5; i>0; i--){
      push(&head, i);
  }
  findmiddle(head);

  return 0;

}