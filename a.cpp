void reverse(Node* &head){
    if (head == NULL){
        return;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* next = curr -> link;
    while(curr != NULL){
        next = curr -> link;
        curr -> link = prev;
        prev = curr;
        curr = next;
    }
    head = prev;

}

void reverseRecursive(Node* &head, Node* curr){
    //basecase
    if (curr-> link == NULL){
        head = curr;
        return;
    }

    //rec
    Node* next = curr -> link;
    reverseRecursive(head, next);
    next -> link = curr;
}