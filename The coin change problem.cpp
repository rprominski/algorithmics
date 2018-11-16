#include<iostream>
using namespace std;
int main()
{
    long long int t,n,a;
    cin>>n>>t;
    long long int tab[300];
    for(int i=1;i<300;i++)
        tab[i]=0;

    tab[0]=1;

    for(int i=0;i<t;i++)
    {
        cin>>a;
        for(int j=0;j<=n;j++)
        {
            if(tab[j]!=0 && j+a<=n)
                tab[j+a]+=tab[j];
        }
    }

    cout<<tab[n]<<endl;


    return 0;
}
