#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <numeric>
#include <string>
// print elements of an STL container
template <typename T>
void printx (T const& coll)
{
    typename T::const_iterator pos;  // iterator to iterate over coll
    typename T::const_iterator end(coll.end());  // end position

    for (pos=coll.begin(); pos!=end; ++pos) {
        std::cout << *pos << ' ';
    }
    std::cout << std::endl;
}
using namespace std;
typedef vector<int> vi;
typedef long long int ll;

int main(){
    int t,n, flag;
    ll first, curr;

    cin >> t;
    while (t--){
        cin >> n;
        cin >> first;
        flag = 0;
        for (int i = 1; i < n; i++){
            cin >> curr;
            if (curr % first != 0){
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }


    }
    return 0;
}