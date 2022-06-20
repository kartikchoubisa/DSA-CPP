#include <iostream>
#include <vector>
using namespace std;


class Heap  {
    vector<int> v;
    bool minHeap;

    bool compare(int a, int b){
        if (minHeap){
            return a<b;
        }
        else {
            return a>b;
        }

    }

    public:
        Heap (int default_size = 10, bool type = true){
            v.reserve(default_size);
            v.push_back(-1);
            minHeap = type;
        }

        void push(int d){
            v.push_back(d);
            int n = v.size() -1;
            int parent = n/2;
        

            while(n > 1 and compare(v[n],v[parent])){
                swap(v[n],  v[parent]);
                n = parent;
                parent = parent / 2;
            }
        }

        
};

int main(){
    cout << "hi";
    vector<int> heap;


}