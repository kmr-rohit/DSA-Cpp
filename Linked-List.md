# Linked List

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
