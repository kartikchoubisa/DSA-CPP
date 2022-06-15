#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <utility>
using namespace std;

class Node {
    public : 
        int data;
        Node* left;
        Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }

};

class LinkedList{ //used in flattenToLinkedList
    public:
        Node* head;
        Node* tail;

    LinkedList(Node* x, Node* y){
        head = x;
        tail = y;
    }
};



void printBT(const string& prefix, const Node* node, bool isLeft)
{
    if( node != nullptr )
    {
        cout << prefix;

        cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->data << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void printBT(const Node* node)
{
    printBT("", node, false);    
}




Node* insertInBST(int d, Node* root){
    // basecase
    if (root == NULL){
        Node* n = new Node(d);
        return n;
    }


    //rec
    if (d<root->data){
        root->left = insertInBST(d, root->left);
    }
    else {
        root -> right = insertInBST(d, root->right);
    }

    return root;
}

Node* build(vector<int> a){

    //read an array of numbers and insert to BST

    Node* root = NULL;

    for (int x: a){
        root = insertInBST(x, root);
    }

    return root;
}

Node* search(Node* x, int target){
    // base
    if (x==NULL){
        return NULL;
    }
    if (x->data == target){
        return x;
    }

    // rec
    if (target < x->data){
        return search(x->left, target);
    }
    else{
        return search(x->right, target);
        }
    
}

Node* deleteNode(Node* root, int data){
    // basecase
    if (root == NULL){
        return NULL;
    }
    // search
    else if (data < root->data){
        root -> left = deleteNode(root -> left, data);
        return root;
    }
    
    else if (data == root -> data) {
        // data == root->data, so current node is the node to delete
        // case 1: no child
        if (root -> left == NULL & root -> right == NULL){
            delete root;
            return NULL; //this returns NULL to the parent
        }

        //case 2: one child
        else if (root -> left == NULL & root -> right != NULL){
            //right child exists
            Node* temp = root -> right; //this temp node gets deleted once funciton stack deletes
            delete root; //delete the curr node (which exists outisde the function)
            return temp;
        }
        else if (root -> left != NULL & root -> right == NULL){
            Node* temp = root -> left;
            delete root;
            return temp;
        }

        //case 3: 2 children
        Node* replace = root -> right; //smallest in the right subtree
        while (replace -> left != NULL){
            replace = replace -> left;
        }
        root -> data = replace -> data;
        root -> right = deleteNode(root -> right, replace -> data);
        return root;
    }
    
    else {
        root -> right = deleteNode(root -> right, data);
        return root;
    }
}

bool is_BST(Node* root, int low, int high){
    //basecase
    if (root == NULL){
        return true;
    }

    //rec
    int x = root -> data;
    return (low < x && x < high) && is_BST(root->left, low, x) && is_BST(root->right, x, high);
}

LinkedList flattenToLinkedList(Node* root){
    //basecase
    if (root == NULL){
        return LinkedList(NULL, NULL);
    }

    Node* LH;
    Node* LT;
    Node* RH;
    Node* RT;

    LinkedList LHLT = flattenToLinkedList(root -> left);
    LinkedList RHRT = flattenToLinkedList(root -> right);

    LH = LHLT.head;
    LT = LHLT.tail;
    RH = RHRT.head;
    RT = RHRT.tail;

    //recursion: we assume we get linked list from both left and right side of curr node
    //the way we join the left and right linked list changes:
    //case 1; if leaf node, then, no need to join anything
    if (root -> left == NULL && root -> right == NULL){
        return LinkedList(root, root);
    }
    else if (root -> left != NULL && root -> right == NULL){
        LT -> right = root;
        root -> left == NULL;
        return LinkedList(LH, root);
    }
    else if (root -> left == NULL && root -> right != NULL){
        root -> right = RH;
        return LinkedList(root, RT);
    }

    //else: only remaining case: root -> left != NULL && root -> right != NULL
    
    LT -> right = root;
    root -> right = RH;
    root -> left = NULL;
    return LinkedList(LH, RT);
}

Node* PreorderToBST(vector<int> &A, int &i, int bound = INT_MAX){
    //basecase
    if (A[i] > bound){
        return NULL;
    } 
    else if (i == A.size()){
        return NULL;
    }

    //rec
    Node* x = new Node(A[i]);
    i++;
    x -> left = PreorderToBST(A, i, x->data);
    x -> right = PreorderToBST(A, i, bound);
    return x;
}

int main(){
    // Node* root = build(vector<int>{6,3,8,4,7,9,2});

    // Node* search_result = search(root, 3);
    // if (search_result == NULL){
    //     cout << "not found";
    // }
    // else{
    //     cout << search_result->data;
    // }

    // deleteNode(root, 4);

    // Node* x = new Node(6);
    // root -> left -> left = x;
    // cout << (is_BST(root, INT_MIN, INT_MAX) ? "True" : "False");
    // printBT(root);

    //flatten:
    // Node* head = flattenToLinkedList(root).head;
    // printBT(head);


    //preordertobst
    int i = 0;
    vector<int> A{8,10,9};
    Node* root = PreorderToBST(A, i, INT_MAX);
    printBT(root);
    cout << (root -> right -> left)->data;
}