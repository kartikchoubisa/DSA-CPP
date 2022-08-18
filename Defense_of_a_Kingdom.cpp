#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int xdim, ydim, n;
        cin >> xdim >> ydim >> n;
        if(n==0){
            cout << xdim*ydim << endl;
            continue;
        }
        vector<int> X(n+2);
        vector<int> Y(n+2);
        for (; n>0; n--){
            int x, y;
            cin >> x >> y;
            X.push_back(x);
            Y.push_back(y);
        }
        X.push_back(0);
        X.push_back(xdim+1);
        Y.push_back(0);
        Y.push_back(ydim+1);

        sort(X.begin(), X.end());
        int x_win = 0;
        for (int i = 0; i < X.size()-1; i++){
            x_win = max(x_win, X[i+1]-X[i]-1);
        }
        sort(Y.begin(), Y.end());
        int y_win = 0;
        for (int i = 0; i < Y.size()-1; i++){
            y_win = max(y_win, Y[i+1]-Y[i]-1);
        }

        cout << y_win*x_win << endl;
    }
    return 0;
}