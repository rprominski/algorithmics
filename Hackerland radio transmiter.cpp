#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long int t,n,ile=0,poz,transpoz;
    bool strona=1;
    cin>>t>>n;
    long long int tab[t+11];
    for(int i=0;i<t;i++)
    {
        cin>>tab[i];
    }

    sort(tab,tab+t);

    poz=tab[0];
    for(int i=1;i<t;i++)
    {
        if(poz+n<tab[i])
        {
            ile++;
            transpoz=tab[i-1];
            while(i<t)
            {
               // cout<<transpoz<<" "<<tab[i]<<" "<<poz<<endl;
                if(tab[i]-transpoz>n)
                {
                    poz=tab[i];
                    break;
                }
                i++;
            }
        }
    }

    if(tab[t-1]-transpoz>n
       )
        ile++;
    if(ile==0)
        ile++;
    cout<<ile<<endl;
    return 0;
}
