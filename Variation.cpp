 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> A(n);
    for(int i=0; i<n; i++){
        cin>>A[i];
    }

    sort(A.begin(), A.end());
    
    int set_size = 0;

    for(int i = 0; i<= n-2; i++){
        for(int j=i+1; j<=n-1; j++){
            if(A[j]-A[i] >= k){
                set_size += n-j;
                break;
            }
        }
    }

    cout<<set_size;
}