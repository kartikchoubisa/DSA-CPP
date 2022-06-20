#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <functional>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;


class X{

    priority_queue<int, vector<int>, greater<int>> x;
    void helper(int num){
        x.push(num);
    }

    public:

        priority_queue<int, vector<int>, greater<int>> result(){
            helper(3);
            return x;
        }

};

int main() {
    X x = X();
    cout << x.result().top()<<endl;
}