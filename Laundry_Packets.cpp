#include <iostream>
#include <vector>
using namespace std;

int fib(int n){
    vector<int> dp(100, 0);
    dp[1] = 1;

    for (int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}


int main()
{   
    cout << fib(7);
}