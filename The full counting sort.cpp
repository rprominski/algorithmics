#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

int main()
{
    multiset<pair<long long int,string> > mapa;
    long long int t,n;
    long long int dzielnik=15485447;
    string a;
    cin>>t;
    for(long long int i=0;i<t;i++)
    {
        cin>>n>>a;
        if(i<t/2)
            a="-";
        n=dzielnik*n+i;
        mapa.insert(make_pair(n,a));

    }

    for(multiset<pair<long long int,string> >::iterator it=mapa.begin();it!=mapa.end();it++)
    {
        cout<<it->second<<" ";
    }

    return 0;
}

