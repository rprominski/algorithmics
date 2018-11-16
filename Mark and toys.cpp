#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;

int main()
{
    int t,n,sum=0,il=0;
    cin>>t>>n;
    int tab[t];
    for(int i=0;i<t;i++)
    {
        cin>>tab[i];
    }

    sort(tab,tab+t);

    for(int i=0;i<t;i++)
    {
        if(sum+tab[i]<=n)
        {
            sum+=tab[i];
            il++;
        }
        else
            break;
    }

    cout<<il<<endl;
    return 0;
}
