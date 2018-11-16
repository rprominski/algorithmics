#include<iostream>
using namespace std;

int main()
{

    int res=0,a,b;
    cin>>a>>b;

    for(int i=a;i<=b;i++)
    {
        for(int j=i;j<=b;j++)
        {
            res=max(res,i^j);
        }
    }

    cout<<res<<endl;
    return 0;
}
