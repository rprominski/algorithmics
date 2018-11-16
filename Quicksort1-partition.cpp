#include<iostream>
#include<vector>
using namespace std;

int main()
{

    long long int n,res=0,x,s,a;
    vector<int> les;
    vector<int> eq;
    vector<int> gr;
    cin>>n;
    cin>>x;
    eq.push_back(x);
    for(int i=0;i<n-1;i++)
    {
        cin>>a;
        if(a==x)
            eq.push_back(a);
        if(a<x)
            les.push_back(a);
        if(a>x)
            gr.push_back(a);
    }
    for(auto i:les)
    {
        cout<<i<<" ";
    }
    for(auto i:eq)
    {
        cout<<i<<" ";
    }

    for(auto i:gr)
    {
        cout<<i<<" ";
    }
    return 0;
}
