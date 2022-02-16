/* Given the head of a sorted linked list,
 delete all duplicates such that each element appears only once.
 Return the linked list sorted as well.*/

 /* Example 1:
Input: head = [1,1,2]
Output: [1,2]

Example 2:
Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

};

void printList(Node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
 void push(Node **head_ref, int new_data) {
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void deleteDuplicates(Node *head) {
    Node * temp = head;
    while(temp!= NULL && temp->next != NULL) {
        if(temp->data == temp->next->data) {
            temp->next = temp->next->next;
        }
        else {
            temp = temp->next;
        }
    }
}

int main() {
    Node *head = NULL;
    push(&head, 1);
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 3);
    printList(head);
    deleteDuplicates(head);
    printList(head);
    return 0;
}