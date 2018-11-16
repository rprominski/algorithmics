#include<iostream>
using namespace std;
int main()
{
    int x;
    cin>>x;

    for(int i=0;i<x;i++)
    {
        long long int t,xorSuma=0,a;
        cin>>t;
        for(int i=0;i<t;i++)
        {
            cin>>a;
            if(a%2==0)
                a--;
            else
                a++;
            xorSuma^=a;
        }
        if(xorSuma==0)
            cout<<"L"<<endl;
        else
            cout<<"W"<<endl;
    }

    return 0;
}
