
#include <bits/stdc++.h>
using namespace std;

int main() {

  int n, v, w;
  cin >> n >> v >> w;

  vector<vector<int>> N(n);
  for (int i = 0; i < n; i++) {
    vector<int> temp(2);
    cin >> temp[0] >> temp[1];
    N[i] = temp;
  }

  vector<int> V(v);
  for (int i = 0; i < v; i++) {
    cin >> V[i];
  }

  vector<int> W(w);
  for (int i = 0; i < w; i++) {
    cin >> W[i];
  }

  sort(V.begin(), V.end());
  sort(W.begin(), W.end());

  // for start

  sort(N.begin(), N.end(), [](auto &a, auto &b) { return a[0] < b[0]; });

  int N_ind = N.size() - 1;
  int i = V.size() - 1;

  while (i != -1 && N_ind != -1) {
    if (V[i] <= N[N_ind][0]) {
      N[N_ind].push_back(V[i]);
      N_ind--;
    } else {
      i--;
    }
  }

  // remove inaccessible tests (test start before first wormhole, or ends after
  // last)

  for (int i = 0; i < N.size(); i++) {
    if (N[i][0] < V[0]) {
      N[i].push_back(-1);
    } else {
      break;
    }
  }

  // for end

  sort(N.begin(), N.end(), [](auto &a, auto &b) { return a[1] < b[1]; });

  N_ind = 0;
  i = 0;

  while (i != W.size() && N_ind != N.size()) {
    if (W[i] >= N[N_ind][1]) {
      N[N_ind].push_back(W[i]);
      N_ind++;
    } else {
      i++;
    }
  }

  // remove inaccessible tests (test start before first wormhole, or ends after
  // last)

  for (int i = N.size() - 1; i >= 0; i--) {
    if (N[i][1] > W[W.size() - 1]) {
      N[i].push_back(-1);
    } else {
      break;
    }
  }

  int min = 1000000;

  for (auto v : N) {
    if (v[3] == -1 || v[2] == -1) {
      continue;
    }
    if (v[3] - v[2] < min) {
      min = v[3] - v[2] + 1;
    }
  }

  cout << min;
//   for (auto v : N) {

//     cout << "(" << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3]
//          << "), ";
//   }

  // for(auto i: V){
  //     cout<<i<<" ";
  // }
}