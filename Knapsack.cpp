#include<iostream>
using namespace std;
int main()
{
    long long int t,inf=1000000,n,k;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>k;
        int nom[n],a;
        int tab[k+1];
        for(int j=0;j<=k;j++)
        {
            tab[j]=inf;
        }
        tab[0]=0;
        for(int j=0;j<n;j++)
        {
            cin>>a;
            for (int q=0;q<=k-a;q++)
            {
                if (tab[q] < inf)
                {
                    if (tab[q]+1 < tab[q+a])
                    {
                        tab[q+a] = tab[q]+1;
                    }
                }
            }
        }

        for(int j=k;j>=0;j--)
        {
            if(tab[j]!=inf)
            {
                cout<<j<<endl;
                break;
            }
        }
    }



    return 0;
}
