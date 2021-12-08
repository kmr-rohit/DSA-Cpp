// Question is to reverse the next half of a linked list.
// example1: input: 1-2-3-4-5-6
//          output: 1-2-3-6-5-4
// example2: input: 1-2-3-4-5
//         output: 1-2-5-4-3

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

Node *reverse(Node *head){
	Node *pre = NULL, *cur = head, *next = NULL;
	while(cur){
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}
Node *reverse2ndHalfOfLinkedList(Node *head){
	Node *fast = head, *slow = head, *pre = NULL;
	while(fast && fast->next){
		pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	if(!fast) pre->next = reverse(slow);
	else slow->next = reverse(slow->next);
	return head;
}

int main()
{
  Node *head = NULL;
  push(&head, 6);
  push(&head, 5);
  push(&head, 4);
  push(&head, 3);
  push(&head, 2);
  push(&head, 1);
  print(head);
  head = reverse2ndHalfOfLinkedList(head);
  print(head);
  return 0;
}