#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;




int main() {
  int N, W;
  cin >> N >> W;
  vector<int> v(N);
  for (int i=0; i<N; i++){
      cin >> v[i];
  }
  sort(v.begin(), v.end());
  int height = 1;
  int curr_width = 0;
  int i = 0;
  while (i<=N-1){
      if (curr_width + v[i] <= W){
        curr_width += v[i];
        i++;

      }
      else {
          curr_width = 0;
          height += 1;
      }
  }

  cout << height;

}