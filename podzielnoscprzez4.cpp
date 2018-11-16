#include<iostream>
using namespace std;
int dwojki(int t)
{
    if(t<=1)
        return 0;

    int d=1,res=-1;
    while(d<t)
    {
        res++;
        d*=2;
    }

    return t/2+res*(res-1)/2;
}

int main()
{
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int pot=1,pot2=1,pos,pos2,mianownik=0;
        cin>>n;
        while(pot2*2<n)
        {
            pot2*=2;
        }
        pos=pot;
        pos2=n-1;

        cout<<pos<<" "<<pot<<endl<<pos2<<" "<<pot2<<endl;
        for(int j=0;j<n;j++)
        {
            cout<<j<<" "<<dwojki(j)<<" "<<dwojki(n-j)<<endl;
        }
    }

    return 0;
}
