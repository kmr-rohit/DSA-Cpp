/*You are   given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    
};

void print(Node *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
void push(Node **head, int val) {
    Node *newNode = new Node();
    newNode->val = val;
    newNode->next = *head;
    *head = newNode;
}

    
int main() {
    Node *head1 = NULL;
    Node *head2 = NULL;
    push(&head1, 1);
    push(&head1, 2);
    push(&head1, 4);
    push(&head2, 1);
    push(&head2, 3);
    push(&head2, 4);
 

    return 0;
}