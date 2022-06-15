#include <stack>
#include <iostream>
#include <math.h>
using namespace std;



int prefixEvaluation(string s){
  stack<int> st;

  for (int i = s.length()-1; i>=0; i--){
    char c = s[i];
    if (c>='0' && c<='9'){
      st.push(c-'0');
    } else {
      int op1 = st.top();
      st.pop();
      int op2 = st.top();
    //   st.pop();

      switch (c) 
      {
        case '+':
          st.push(op1+op2);
          break;
        case '-':
          st.push(op1-op2);
          break;
        case '/':
          st.push(op1/op2);
          break;
        case '^':
          st.push(pow(op1,op2));
          break;
      }
    }
  }


  return st.top();
}

int main() {
string s = "-+7*56+20";
int ans = prefixEvaluation(s);
cout<<ans;
}