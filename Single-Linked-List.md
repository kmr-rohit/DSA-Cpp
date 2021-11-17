# Single Linked List

It is the collection of nodes, where each nodes contain data and pointer to next node.
![image](https://user-images.githubusercontent.com/80917122/142045323-292326fd-ae3d-409d-bf63-f1010bdf00ec.png)


Here in the given Example there are 4 nodes each node contains a value and a address of memory in which that value is stored and that is linked by a pointer to the same type of next node

For the First node : value is 4 and adress of memory is 200 and is lined to another node named 2nd .

Head pointer : it is the pointer pointing the first node in an given linked list a

Node Structure

```cpp
#include<iostream>
using namespace std;

class Node
{
  public:
  int data ;
  Node* next;
};
```

Operation on Single-Linked- List: 

1. Insertion 
2. Deletion

### Insertion:

An Element in a Linked List can be inserted at  3 positions : 

1. At the front 
2. after a given node 
3. at the end 

We will see code implementations of these insertions.

 

A. Insertions at Front of linked list 

It is 4 Step process: 

1. Allocating a new node 
2. Setting value in new node data 
3. linking next of new node to old head 
4. making new head 

![image](https://user-images.githubusercontent.com/80917122/142045384-fe9c1c63-b033-45d7-b28c-759716861c8f.png)


```cpp
void push(Node** head_ref, int new_data)

    /* 1. allocate node */
    Node* new_node = new Node();
 
    /* 2. put in the data */
    new_node->data = new_data;
 
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
 
    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}
```

Time complexity of push() is O(1)

B. Insertion after a Given Node: 

5 Step Process: 

1. checking if(prev node ) == null
2. allocating a new node 
3. setting val to data 
4. changing new_node next to prev_node next 
5. changing prev_node to new node 

![image](https://user-images.githubusercontent.com/80917122/142045446-3636ee67-9deb-43de-bf59-8920a84e0a73.png)


```cpp
void insertAfter(Node* prev_node, int new_data)
	// insertAfter function need 2 things as input 
	// 1st = pointer to prev node after which given val to be added 
	// 2nd = value to be added  
{
   
    // 1. Check if the given prev_node is NULL
    if (prev_node == NULL) 
    { 
        cout << "The given previous node cannot be NULL"; 
        return; 
    }
   
    // 2. Allocate new node
    Node* new_node = new Node();
   
    // 3. Put in the data
    new_node->data = new_data; 
   
    // 4. Make next of new node as
    // next of prev_node
    new_node->next = prev_node->next; 
   
    // 5. move the next of prev_node
    // as new_node
    prev_node->next = new_node; 
}
```

Time complexity of insertAfter() is O(1) as it does a constant amount of work.

C. Insertion at the end 

6 step process: 

1. allocating a new node 
2. creating temp pointer as pointer to head_ref
3. setting next of new node to NULL 
4. If ( ll is empty make new_node as head) 
5. else( traverse till the last of ll) 
6. Changing the next of last node 
![image](https://user-images.githubusercontent.com/80917122/142045484-4fe12afa-2108-4a74-a993-f1ce7f6c335f.png)


```cpp
// Given a reference (pointer to pointer) to the head 
// of a list and an int, appends a new node at the end
void append(Node** head_ref, int new_data) 
{ 
   
    // 1. allocate node
    Node* new_node = new Node();
   
    // Used in step 5
    Node *last = *head_ref;
   
    // 2. Put in the data
    new_node->data = new_data; 
   
    // 3. This new node is going to be 
    // the last node, so make next of 
    // it as NULL
    new_node->next = NULL; 
   
    // 4. If the Linked List is empty,
    // then make the new node as head
    if (*head_ref == NULL) 
    { 
        *head_ref = new_node; 
        return; 
    } 
   
    // 5. Else traverse till the last node
    while (last->next != NULL)
    {
        last = last->next; 
    }
   
    // 6. Change the next of last node
    last->next = new_node; 
    return; 
}
```

Time complexity of append is O(n) where n is the number of nodes in the linked list. Since there is a loop from head to end, the function does O(n) work.


### Deletion.

Deletion in linked list  can be done in 2 ways 

1. Deleting a given key 
2. Deleting a  key at a given position 

**Deleting a given key**

*Given a ‘key’, delete the first occurrence of this key in the linked list*.

**Iterative Method:**

To delete a node from the linked list, we need to do the following steps.

1) Find the previous node of the node to be deleted.

2) Change the next of the previous node.

3) Free memory for the node to be delete

```cpp
// Given a reference (pointer to pointer)
// to the head of a list and a key, deletes
// the first occurrence of key in linked list
void deleteNode(Node** head_ref, int key)
{
     
    // Store head node
    Node* temp = *head_ref;
    Node* prev = NULL;
     
    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }
 
    // Else Search for the key to be deleted,
    // keep track of the previous node as we
    // need to change 'prev->next' */
      else
    {
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
        return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    // Free memory
    delete temp;
    }
    
}
```

**Recursive Method:**

To delete a node of a linked list recursively we need to do the following steps.

1.We pass node* (node pointer) as a reference to the function (as in node* &head)

2.Now since current node pointer is derived from previous node’s next (which is passed by reference) so now if the value of the current node pointer is changed, previous next node’s value also gets changed which is the required operation while deleting a node (i.e points previous node’s next to current node’s (containing key) next).

3.Find the node containing the given value.

4.Store this node to deallocate it later using free() function.

5.Change this node pointer so that it points to it’s next and by performing this previous node’s next also get properly linked.

![image](https://user-images.githubusercontent.com/80917122/142129282-8e400a5d-bc38-446a-8200-42af8a40920d.png)


```cpp
/*
Deletes the node containing 'info' part as val and
alter the head of the linked list (recursive method)
*/
void deleteNode(node*& head, int val)
{
     
    // Check if list is empty or we
    // reach at the end of the
    // list.
    if (head == NULL) {
        cout << "Element not present in the list\n";
        return;
    }
    // If current node is the node to be deleted
    if (head->info == val) {
        node* t = head;
        head = head->link; // If it's start of the node head
                           // node points to second node
        delete (t); // Else changes previous node's link to
                    // current node's link
        return;
    }
    dele
```


Deleting a key at given position.

Given a singly linked list and a position, delete a linked list node at the given position.

If the node to be deleted is the root, simply delete it. To delete a middle node, we must have a pointer to the node previous to the node to be deleted. So if positions are not zero, we run a loop position-1 times and get a pointer to the previous node.

```cpp
// Given a reference (pointer to pointer) to
// the head of a list and a position, deletes
// the node at the given position 
void deleteNode(Node **head_ref, int position)
{
      
    // If linked list is empty
    if (*head_ref == NULL)
        return;
      
    // Store head node
    Node* temp = *head_ref;
  
    // If head needs to be removed
    if (position == 0)
    {
          
        // Change head
        *head_ref = temp->next; 
          
        // Free old head
        free(temp);             
        return;
    }
  
    // Find previous node of the node to be deleted
    for(int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
  
    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;
  
    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
     Node *next = temp->next->next;
  
    // Unlink the node from linked list
    free(temp->next); // Free memory
      
    // Unlink the deleted node from list
    temp->next = next; 
}
```

