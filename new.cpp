#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> answer;
    int n = intervals.size();
    int i = 0;
    int start, end;
    while (i <= n - 1) {
      if (i == n - 1) {
        start = intervals[i][0];
        end = intervals[i][1];
        answer.push_back(vector<int>{start, end});
        break;
      }
      start = intervals[i][0];

      while (intervals[i][1] >= intervals[i + 1][0]) {
        i++;
        if (i == n - 1) {
          break;
        }
      }
      end = intervals[i][1];
      answer.push_back(vector<int>{start, end});
      i++;
    };
  };
};
