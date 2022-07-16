using namespace std;
void insert(stack<int>&s,int e)
{
    if(s.size()==0)
    {
        s.push(e);
        return;
    }
    int temp=s.top();
    s.pop();
    insert(s,e);
    s.push(temp);
}
void rever(stack<int>&s)
{
    if(s.size()==0)
    {
        return;
    }
    int temp=s.top();
    s.pop();
    rever(s);
    insert(s,temp);
}
int main()
{
    int n;
    cin>>n;
    stack<int>st;
    for(int i=0;i<n;i++)
    {

        int a;
        cin>>a;
        st.push(a);
    }
    rever(st);
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}
