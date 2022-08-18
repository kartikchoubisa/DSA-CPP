#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ispossible(int s, vector<int> stalls, int c){
    //is it possible to have separation of s between each cow in stalls
    int prev = stalls[0];
    c--;
    for (int i = 1; i < stalls.size(); i++){
        if (stalls[i] - prev >= s){
            c--;
            prev = stalls[i];
            if (c == 0){
                return true;
            }
        }
    }
    return false; 
}

int main(){
    
    int t;
    cin >> t;

    while (t--){
        int N, C;
        cin >> N >> C;
        vector<int> stalls(N);
        for (int i=0; i < N; i++){
            cin >> stalls[i];
        }
        
        sort(stalls.begin(), stalls.end());
        int s = 0;
        int e = 1000000000;
        int mid = s + (e-s)/2;
        int curr_ans;

        curr_ans = ispossible(10,stalls,C);

        while (s <= e) {
            mid = s + (e-s)/2;
            if (ispossible(mid, stalls, C)){
                curr_ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }

        }
        cout << curr_ans << endl;
    }

    return 0;
}
