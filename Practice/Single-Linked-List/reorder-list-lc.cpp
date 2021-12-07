// leetcode problem 143 link: https://leetcode.com/problems/reorder-list/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

void push(Node **head_ref, int new_data)
{
  /* allocate node */
  Node *new_node = new Node();

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
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

void reorderList(Node *head)
{

  Node *temp = head;
  Node *ptr = head;
  Node *end = head;
while(ptr->next!=NULL){
  while (temp->next->next != NULL)
  {
    temp = temp->next;
  }

  end = temp->next;      // store address of last node
  temp->next = NULL;     // make second last node last node
  end->next = ptr->next; // set address of second node(ptr->next) in last node(end)
  ptr->next = end;       // set address of last node in first node(ptr)
  if (ptr->next->next == NULL){
    break;
  }
  ptr = ptr->next->next;
  temp = ptr;
}
}

int main(){
  Node * head = NULL;
  push(&head, 5);
  push(&head, 4);
  push(&head, 3);
  push(&head, 2); 
  push(&head, 1);
  reorderList(head);
  print(head);
}