
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


//"204" -> (int) 204

int main(){
  vector<int> v{4,1,2,3};
  printx(v);
  int i = v.size() -1;
  for(; i > 0; i--){
    if (v[i] > v[i-1]) break;
  }
  if(i == 0){
    reverse(v.begin(), v.end());
  }
  else{
    swap(v[i-1],v[i]);
    reverse(v.begin()+i+1,v.end());
  }
  printx(v);
}