#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
};
Node* print(Node * head){
  while(head->next != NULL){
    cout<<head->data<<" ";
    head = head->next;
  }

}

Node* reverseList(Node* head) {
        Node* prev=NULL;
        Node* cur=head;
        Node* n;
        while(cur!=NULL){
            n=cur->next;
            cur->next=prev;
            prev=cur;
            cur=n;
        }
        return prev;
        
        
    }

vector<int>reversal(Node * head){
      vector<int>result;
      while(head->next != NULL){
        result.push_back(head->data);
      head = head->next;
  }
  reverse(result.begin() , result.end());
  return result;
}

  


Node* addTwoNumbers(Node* l1, Node* l2) {
        Node *dummy = new Node(); 
        Node *temp = dummy; 
        int carry = 0;
        int last =0;
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->data; 
                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) {
                sum += l2 -> data; 
                l2 = l2 -> next; 
            }
            
            sum += carry;
            carry = sum / 10;
            last = carry; 
            Node *node = new Node();
            node->data = sum % 10;
            
            
            temp -> next = node; 
            temp = temp -> next; 
        }
        Node* node = new Node();
        node->data = last;
        temp -> next = node; 
        temp = temp -> next; 
        dummy = dummy->next;
        return dummy; 
    }

  
int main(){
  Node*head1 = new Node();
  head1->data = 4;
  head1->next = new Node();
  head1->next->data = 8;
  head1->next->next = new Node();
  head1->next->next->data = 9;
  head1->next->next->next = NULL;

  Node*head2 = new Node();
  head2->data = 7;
  head2->next = new Node();
  head2->next->data = 5;
  head2->next->next = new Node();
  head2->next->next->data = 8;
  head2->next->next->next = NULL;

  Node* temp1 = reverseList(head1);
  Node* temp2 = reverseList(head2);
  Node* ans = addTwoNumbers(temp1 , temp2);
  vector<int> output = reversal(ans);
  for(int i = 0 ; i<output.size() ; i++){
    cout<<output[i]<<" ";

  }

}
