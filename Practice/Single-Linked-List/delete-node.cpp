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
void print(Node *head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void deletenode(Node * given){
  
  given->data = given->next->data;
  given->next = given->next->next;
  

}

int main(){
  Node * head = NULL;
  push(&head, 5);
  push(&head, 4);
  push(&head, 3);
  push(&head, 2);
  push(&head, 1);
  Node* given = head;
  deletenode( given );
  print(head);

}