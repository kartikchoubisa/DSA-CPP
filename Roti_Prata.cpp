
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

bool isvalid(int time_, vector<int> cooks, int p){
  //return true if cooks can finish p pratas in time_ minutes
  
  for (int R: cooks){
    //how many pratas can he cook in time_ mins
    int count = 0;
    int curr_time = 0;
    while(true){
      if (curr_time + R*(count+1)<= time_){
        curr_time += R*(count+1);
        p--;
        count++;
      }
      else{
        break;
      }
    }
    if (p<=0){
      return true;
    }
  }

  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--){
    int P, L;
    cin >> P >> L;
    vector<int> cooks;
    int cook;
    for(int i =0; i<L; i++){
      cin >> cook;
      cooks.push_back(cook);
    }

    //search sp : min time
    int start = 0;
    int end = INT_MAX;

    int mid;
    int ans;

    while(start!=end+1){
      mid = start + (end - start)/2;
      
      // if cooks can cook in mid time:
      if (isvalid(mid, cooks, P)){
        ans = mid;
        end = mid - 1;
      }
      else {
        start = mid + 1;
      }
    }

    cout<<ans<<endl;
  }


  return 0;
}