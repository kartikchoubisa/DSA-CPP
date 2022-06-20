#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <functional>
#include <queue>
#include <algorithm>
using namespace std;

class Triplet
{
public:
    int val;
    int i;
    int j;
    Triplet(int val, int i, int j)
    {
        this->val = val;
        this->i = i;
        this->j = j;
    }
};

class greaterTriplet
{
public:
    bool operator()(Triplet t1, Triplet t2)
    {
        return t1.val > t2.val;
    }
};

int main()
{

    priority_queue<Triplet, vector<Triplet>, greaterTriplet> p;

    vector<vector<int>> A{
        {2, 6, 12, 15},
        {1, 3, 14, 20},
        {3, 5, 8, 10}
    };

    int K = A.size();
    int N = A[0].size();


    for (int i = 0; i<K; i++){
        p.push(Triplet(A[i][0], i, 0));
    }

    vector<int> result;
    while(!p.empty()){
        result.push_back(p.top().val);
        if (p.top().j == N-1){
            p.pop();
        } else {
            int i = p.top().i;
            int j = p.top().j;
            p.pop();
            p.push(Triplet(A[i][j+1],i,j+1));
        }
    }
    for (auto x: result){
        cout << x << " ";
    }
}