#include<iostream>
using namespace std;
int main()
{
    long long int xorSuma,t,a,res=0;
    cin>>t;
    long long int tab[t];
    for(int i=0;i<t;i++)
    {
        cin>>tab[i];
        if(i==0)
            xorSuma=tab[i];
        else
            xorSuma^=tab[i];
    }

    for(int i=0;i<t;i++)
    {
        long long int v=tab[i]^xorSuma;
        if(tab[i]>v)
            res++;
    }

    cout<<res<<endl;

    return 0;
}
