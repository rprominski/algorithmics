#include<iostream>
using namespace std;
unsigned long long int potegi2[64];
void wyznacz()
{
    potegi2[0]=1;
    for(int i=1;i<64;i++)
    {
        potegi2[i]=2*potegi2[i-1];
    }
}
void tnij(long long int  &x)
{
    long long int mx=-1;
    for(int i=0;i<64;i++)
    {
        if(x>potegi2[i])
            mx=potegi2[i];
        if(x==potegi2[i])
        {
            x=potegi2[i]/2;
            return;
        }
    }

    x-=mx;
    return;
}
int main()
{
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        long long int t,ruchy=0;
        cin>>t;
        wyznacz();
        while(t>1)
        {
            tnij(t);
            ruchy++;
        }

        if(ruchy%2==0)
            cout<<"Richard"<<endl;
        else
            cout<<"Louise"<<endl;
    }
    return 0;
}
