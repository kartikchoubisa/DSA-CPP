#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
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

Node* buildTree(){
    int d;
    cin >> d;

    if (d == -1){
        return NULL; 
    }

    Node* root = new Node(d);
    root -> left = buildTree();
    root -> right = buildTree();
    return root;
}

Node* buildTreeFromString(deque<int>& nodeData){
    // if (i == end || i == end+1){
    //     return NULL;
    // }

    int d = nodeData[0];
    nodeData.pop_front();

    if (d == -1){
        return NULL;
    }

    Node* root = new Node(d);
    root -> left = buildTreeFromString(nodeData);
    root -> right = buildTreeFromString(nodeData);
    return root;
}

void print(Node* root){ //pre order
    if (root == NULL){
        return;
    }
    cout<< root->data << " ";
    print(root -> left);
    print(root -> right);
}

void print_inorder(Node* root){

    if (root == NULL){
        return;
    }

    print_inorder(root -> left);
    cout << root -> data << " ";
    print_inorder(root -> right);
}

void print_postorder(Node* root){

    if (root == NULL){
        return;
    }

    print_postorder(root -> left);
    print_postorder(root -> right);
    cout << root -> data << " ";
}

int height(Node* root){
    if (root == NULL){
        return 0;
    }

    return max(height(root-> left), height(root->right)) + 1;
}

void printKthLevel(Node* root, int k){
    if (root == NULL){
        return;
    }
    if (k == 0){
        cout << root -> data << " ";
        return;
    }

    printKthLevel(root -> left, k-1);
    printKthLevel(root -> right, k-1);
}

void printEveryLevel(Node* root){
    int height1 = height(root);
    
    for (int k = 1; k < height1 + 1; k++){
        printKthLevel(root, k);
        cout << endl;
    }
    
}

void bfs(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        cout << curr -> data << " ";

        if (curr -> left) q.push(curr -> left);
        if (curr -> right) q.push(curr -> right);
    }
}

void printEveryLevelBFS(Node* root){
    queue<Node*> q;
    q.push(root);
    int i = 0;

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        cout << curr -> data << " ";

        if (curr-> left) q.push(curr -> left);
        if (curr -> right) q.push(curr -> right);
        
        if (i==0){ // if curr node (that we popped) was rightmost,
            cout << "\n"; // print return
            i = q.size() - 1; // mark the next rightmost node
            //next rightmost node is the last child of curr node
            //so it's at the end of the queue right now
        }
        // if curr node was not the right most one, then dec i
        //so that once we pop next item in queue, i will still be at required position
        else i--;

    }
}

int sumOfNodes(Node* curr){
  if (curr == NULL){
    return 0;
  }
  return sumOfNodes(curr -> left) + sumOfNodes(curr -> right) + curr -> data;
}

int countOfNodes(Node* curr){
  if (curr == NULL){
    return 0;
  }
  return countOfNodes(curr -> left) + countOfNodes(curr -> right) + 1;
}

int diameter(Node* root){
    //basecase
    if (root == NULL){
        return 0;
    }
    int curr_diameter = height(root->left) + height(root->right);
    return max(max(diameter(root->left), diameter(root->right)), curr_diameter);
}

pair<int, int> fastDiameter(Node* root){
    //basecase
    if (root == NULL){
        return pair<int,int> {0,0};
    }

    //rec. bottom up / post order traversal
    pair<int, int> x = fastDiameter(root -> left);
    pair<int, int> y = fastDiameter(root -> right);

    int h_left = x.first;
    int d_left = x.second;
    int h_right = y.first;
    int d_right = y.second;
    
    int h = max(h_left, h_right) + 1;
    int d = max(max(d_left, d_right), h_left + h_right);

    return pair<int, int>{h,d};

}

int sumOfChildNodes(Node* root){
    //basecase
    if (root == NULL){
        return 0;
    }

    if (root->left == NULL && root->right == NULL ){
        return root->data;
    }

    //rec (bottom up)
    int left_sum = sumOfChildNodes(root->left);
    int right_sum = sumOfChildNodes(root->right);

    int temp = root -> data;
    root -> data = left_sum + right_sum;
    return left_sum + right_sum + temp;
}

pair<int, bool> heightBalanced(Node* root){
    //basecase
    if (root == NULL){
        return pair<int, bool> {0,true};
    }

    //rec (bottom to up)
    pair<int, bool> x = heightBalanced(root -> left);
    pair<int, bool> y = heightBalanced(root -> right);
    int h1 = x.first;
    bool b1 = x.second;
    int h2 = y.first;
    bool b2 = y.second;
    if (!b1 || !b2){//false returned by any child
        return pair<int, bool> {-1, false}; //height doesn't matter anymore
    }

    int height_diff = abs(h1-h2);

    return pair<int, bool> {max(h1, h2) + 1, height_diff <= 1};

}

Node* buildBalancedTreeFromArray(int start, int end, vector<int> treeData){

    //basecase
    if(start == end + 1){
        return NULL;
    }
    //rec
    int mid = start + (end-start)/2;
    Node* curr = new Node(treeData[mid]);
    curr -> left = buildBalancedTreeFromArray(start, mid-1, treeData);
    curr -> right = buildBalancedTreeFromArray(mid+1, end, treeData);
    return curr;

}


Node* buildBTInorderPreorderhelper(map<int,int> InMap, vector<int> In, vector<int> Pre, int i_start, int i_end, int j_start, int j_end){
    //basecase
    if(i_start > i_end || j_start > j_end) return NULL;

    //rec
    int val = Pre[j_start];
    Node* x = new Node(val);

    int i = InMap[val];
    int len = i-1 - i_start + 1; //no of elements to take from Preorder is i_start to i-1
    x -> left = buildBTInorderPreorderhelper(InMap, In, Pre, i_start, i-1, j_start + 1, j_start + len);
    x -> right = buildBTInorderPreorderhelper(InMap, In, Pre, i+1, i_end, j_start + 1 + len, j_end);

    return x;
}

Node* buildBTInorderPreorder(vector<int> Inorder, vector<int> Preorder){
    //create a map to making seraching in Inorder O(n)
    map<int, int> InMap;
    for (int i; i<Inorder.size(); i++){
        InMap.insert({Inorder[i], i});
    }

    //call the helper recursive fn:
    Node* root = buildBTInorderPreorderhelper(InMap, Inorder, Preorder, 0, Inorder.size()-1, 0, Preorder.size()-1);
    return root;
}



void printRightView(Node* curr, int level, int &maxlevel){
    //basecase
    if (curr == NULL){
        return;
    }
    //rec
    //reached rightmost node (ie, discovered new level)
    if (level>maxlevel){
        cout << curr -> data << endl;
        maxlevel = level;
    }

    //right
    printRightView(curr -> right, level + 1, maxlevel);
    //left
    printRightView(curr -> left, level + 1, maxlevel);

}

int printNodesAtDistanceK(Node* curr, Node* target, int k){
    if (curr == NULL){
        return -1;
    }
    if (curr == target){
        printKthLevel(curr, k);
        cout << " ";
        return 0;
    }

    //rec
    
    int DL = printNodesAtDistanceK(curr -> left, target, k);
    if (DL != -1){
        if (DL+1 == k){
            cout << curr->data << " ";
        }
        else {
            printKthLevel(curr -> right, k - 2 - DL);
        }
        return DL + 1;
    }

    int DR = printNodesAtDistanceK(curr -> right, target, k);
    if (DR != -1){
        if (DR + 1 == k){
            cout << curr -> data << " ";
        }
        else {
            printKthLevel(curr -> left, k - 2 - DR);
        }
        return DR + 1;
    }

    return -1;
}

Node* lca(Node* root, int a, int b){
    //assuming both a and b are present, and all values are unique
    if (root == NULL){
        return NULL;
    }
    if (root -> data == a | root -> data == b){
        return root;
    }

    Node* left = lca(root -> left, a,b);
    Node* right = lca(root -> right, a,b);

    if (left != NULL & right != NULL){
        return root;
    }
    
    //this part will return a node if a match is found
    if (left != NULL){
        return left;
    }
    else if (right != NULL){
        return right;
    }
    else{ // if both are null, return null
        return NULL;
    }
}

int main(){
    // Node* root = buildTree();

    // deque<int> nodeData{1,2, 5, -1, -1 ,-1,3,-1,-1};
    // Node* root = buildTreeFromString(nodeData);
    // print(root);
    // cout<<endl;
    // print_inorder(root);
    // cout<<endl;
    // print_postorder(root);
    // cout<<height(root);
    // printKthLevel(root, 0);
    // printEveryLevelBFS(root);    
    // printEveryLevel(root);
    // cout<<sumOfNodes(root);  
    // cout<<countOfNodes(root);  
    // cout<<diameter(root);
    // cout<<fastDiameter(root).second;
    // sumOfChildNodes(root);
    // cout << (bool) heightBalanced(root).second;

    // vector<int> a{1,2,3,4};
    // Node* root = buildBalancedTreeFromArray(0,a.size()-1,a);

    // int maxlevel = -1;
    // printRightView(root, 0, maxlevel);

    // printNodesAtDistanceK(root, root -> right -> right, 3);
    // cout << lca(root, 1, 7) -> data << endl;
    
    vector<int> In{9,3,15,20,7};
    vector<int> Pre{3,9,20,15,7};
    Node* root = buildBTInorderPreorder(In, Pre);
    
    
    
    printBT(root);
    
}