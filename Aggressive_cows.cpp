#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


class Node{
    public:
        int val;
        Node* left = NULL;
        Node* right = NULL;

    Node(int val){
        this->val = val;
    }
};

Node* build(vector<int>& v){
    int val = v.back();
    v.pop_back();

    //basecase
    if (val == -1){
        return NULL;
    }

    //rec
    Node* x = new Node(val);
    x->left = build(v);
    x->right = build(v);
    return x;
}



int main(){
    vector<int> v{1, 2, -1, 4, 5, -1, -1, 6, -1, -1, 3, -1, -1};
    reverse(v.begin(), v.end());
    Node* root = build(v);
    
    queue<int> q;

    return 0;
}