/* Given linked list head and order change to nodes
to  get desired sequence, wihout changing data of any nodes

example given: 1 2 3 4 5
        output: 1 4 2 3 5

*/

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
    cout<<endl;
}

int main()
{
    Node *head = NULL;
    push((&head), 5);
    push((&head), 4);
    push((&head), 3);
    push((&head), 2);
    push((&head), 1);
    print(head);

    Node * temp= head;
    Node * ptr = head;
    Node * end = NULL;

    while(temp->next->next->next  != NULL){
        temp = temp->next;

    }

    end = temp->next; // stores the 2nd last node
    temp->next = temp->next->next;// links 3 to 5 
    end->next = ptr->next; // links 4 to 2 
    ptr->next = end;// links 1 to 4 

    print(head);
}
