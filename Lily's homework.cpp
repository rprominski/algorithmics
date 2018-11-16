#include<iostream>
#include<map>
using namespace std;
int main()
{
    int n,zamiany=0;
    map<int,int> mapa;
    cin>>n;
    int tab[n];
    int tab2[n];
    for(int i=0;i<n;i++)
    {
        cin>>tab[i];
        mapa[tab[i]]=i;
    }

    for(map<int,int>::iterator it=mapa.begin();it!=mapa.end();it++)

    for(int i=0;i<t;i++)
    {
        if(it->first!=tab[i])
        {
            zamiany++;

        }

        it++;
    }



    return 0;
}
