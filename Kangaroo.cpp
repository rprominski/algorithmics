#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int k1,k2,v1,v2;
    cin>>k1>>v1>>k2>>v2;

    if(k1>k2)
    {
        swap(k1,k2);
        swap(v1,v2);
    }
    v1-=v2;
    if(v1<=0)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        if((k2-k1)%v1==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}

