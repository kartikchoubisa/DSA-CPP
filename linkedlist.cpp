#include <iostream>
#include <stack>
using namespace std;

class Node{
  public:
  int data;
  Node* link;

  Node(int val){
    data = val;
    link = NULL;
  }
};

void insert_at_tail(Node* &head, int val){

  Node* n = new Node(val);

  if (head == NULL){
    head = n;
    // cout<<"link is ("<<n->link<<")";
    return;

  }

  Node* temp = head;
  while (temp -> link != NULL){
    temp = temp -> link;
  }

  temp -> link = n;
}

void insert_at_head(Node* &head, int val){
    Node* n = new Node(val);
    n->link = head;
    head = n;
}

void insert_at_n(Node* &head, int val, int pos){
    Node* node1 = new Node(val);

    if (pos==1){
        node1->link = head;
        head = node1;
        return;
    }
    Node* temp = head;
    for(int i=0; i<pos-2; i++){
        temp = temp->link;
    }
    node1->link = temp->link;
    temp->link = node1;
}

void delete_n(Node* &head, int pos){


    Node* temp = head;

    if (pos==1){
        head = temp->link;
        return;
    }
    for (int i = 0; i < pos-2; i++){
        temp = temp->link;
        }
    temp->link = temp->link->link;

}

void display(Node* head){
  Node* temp = head;
  while(temp!=NULL){
    cout << temp->data<<"-->";
    temp = temp -> link;
  }

  cout<<"NULL\n";
}

void display_recursive(Node* curr){
  if (curr -> link == NULL){
    cout<< curr -> data << "-->NULL\n";
    return;
  }
  cout << curr -> data << "-->";
  display_recursive(curr -> link);
}

void reverse(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    while (curr!=NULL){
        Node* next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void reverseRecursive1(Node* &head, Node* curr){
    //basecase
    if (curr-> link == NULL){
        head = curr;
        return;
    }

    //rec
    Node* next = curr -> link;
    curr -> link = NULL;
    reverseRecursive1(head, next);
    
    next -> link = curr;
}

Node* reverse_recursive(Node* &curr){
  //base
  if (curr -> link == NULL){
    return curr;
  }


  Node* next = curr -> link;
  Node* new_head = reverse_recursive(next);
  curr -> link = NULL;
  next -> link = curr;

  return new_head;
}

Node* kreverse(Node* curr, int k){

  
  Node* temp = curr;
  for(int i = 0; i<k; i++){
    //basecase: NULL is reached
    if (temp == NULL){
      return curr;
    }
      temp = temp->link;
  }

  // rec
  //reversing the k length sublist
  Node* next_head = kreverse(temp, k); //join tail (to-be tail) of this sublist to head of next sublist

  Node* prev = next_head;
  Node* curr1 = curr;
  Node* next = NULL; 

  for (int i =0; i<k; i++){
    next = curr1 -> link;
    curr1 -> link = prev;

    prev = curr1;
    curr1 = next;
  }

  return prev;

}

void reorderListUsingStack(Node* head){
  Node* y = head;
  stack<Node*> s;
  while(y != NULL){
    s.push(y);
    y = y -> link;
  }
  if (s.empty()) return;

  y = s.top();
  Node* x = head;
  Node* x1;

  while(x != y){
    x1 = x -> link;
    if (x1 == y) break;
    x -> link = y;
    y -> link = x1;
    x = x1;
    s.pop();
    y = s.top();
  }

  x1 -> link = NULL;

}

void reorderList(Node* head){
  //find middle node
  Node* x = head;
  Node* y = head;
  Node* tail = x;
  while(y && y -> link){
    tail = x;
    x = x -> link;
    y = y -> link -> link;
  }
  
  //x is the middle node (the right side one in case of two middle nodes)
  tail -> link = NULL; //remove the link between left and right parts

  //reverse the later half (starting form x as head)
  Node* prev = NULL;
  Node* curr = x;
  while(curr != NULL){
    Node* next = curr -> link;
    curr -> link = prev;
    prev = curr;
    curr = next;
  }
  x = prev; //new head of the reversed list is x

  //join the two halves alternatively
  curr = head;
  Node* next = x;

  while(next != NULL){
    Node* temp = curr -> link;
    curr -> link = next;
    curr = next;
    next = temp;
  }
  
}


void Print(Node* p){
  if (p==NULL) return;
  cout<<p->data;
  Print(p->link);
}

int main(){
  
  Node* head = NULL;

  insert_at_tail(head, 1);
  insert_at_tail(head, 2);
  insert_at_tail(head, 3);
  insert_at_tail(head, 4);


  // insert_at_n(head, 1212,2);
  // delete_n(head, 1);
  // reverse(head);
  // head = reverse_recursive(head);
  // reverseRecursive1(head, head);
  // head = kreverse(head, 2);
  // cout<<"hi";
  // reorderList(head);

  display_recursive(head);
}