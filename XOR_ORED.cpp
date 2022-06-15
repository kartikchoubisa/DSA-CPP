#include<iostream>
#include <vector>
#include<numeric>
#include <math.h>       /* pow */
#include <bitset>
using namespace std;
 

void f(vector<int>& arr) {
  arr[3]=5;
  cout<<arr[3]<<"\n";
}

int main()
{
vector<int> a{1,2,7,4,2};

f(a);
for (auto i : a){
  cout<<i<<" ";
}
cout<<"\n";


}