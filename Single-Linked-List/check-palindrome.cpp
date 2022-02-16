/* Question:: Given a single linked list of characters , write a function that returns 
    true if the given palindrome , else false 
*/

// 3 ways to solve this problem 
// 1. use of stack 
// 2. by reversing list about middle and comparing with original 
// 3. Recurrsion 

/* By Use Of Stack
  1. Traverse the given list from head to tail 
   push every visited node to stack

  2.Traverse the list again. For every visited node, pop a node from the stack 
  and compare data of popped node with the currently visited node.

  3. If all nodes matched, then return true, else false.
*/
#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
  int data;
  Node* next;

};

void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}


bool isPalindrome(Node*head){
  // traverse the list to store data in stack 
  Node * slow = head; // creating a temp pointer to traverse linked list 
  stack<int> s; // initialise the stack 
  while(slow != NULL){
    s.push(slow->data);
    slow = slow->next;
  }

  while(head!=NULL){
    int i = s.top();   // assigns i to the top value in stack 
    s.pop() ;    // removes top elemet from stack 
    if(head->data !=  i ){  // checking linked list element with stack 

      return false;

    }
    head = head->next;


  }
  return true;
}

int main(){

  Node* head = NULL;
  push((&head),1);
  push((&head),2);
  push((&head),3);
  push((&head),2);
  push((&head),1);
  

  int result = isPalindrome(head);
  if(result == 1){
    cout<<"The Given Single Linked List is Palindrome";

  }
  else{
    cout<<"The goven Single Linked List is not a Palindrome";
  }
  return 0;

}