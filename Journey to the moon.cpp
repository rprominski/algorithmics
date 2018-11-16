#include<iostream>
#include<queue>
#include<map>
#include<vector>
using namespace std;
int odw[30000];
int main()
{
    int n,m,a,b,sp=1;
    cin>>n>>m;
    vector<vector<int> > tab;
    tab.resize(n+5);

    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        tab[a].push_back(b);
        tab[b].push_back(a);
    }

    for(int i=0;i<n;i++)
    {
        queue<int> kol;

        if(odw[i]==0)
        {
            odw[i]=sp;
            kol.push(i);

            while(!kol.empty())
            {
                int u=kol.front();
                kol.pop();

                for(int j=0;j<tab[u].size();j++)
                {
                    if(odw[tab[u][j]]==0)
                    {
                        odw[tab[u][j]]=sp;
                        kol.push(tab[u][j]);
                    }
                }
            }
            sp++;
        }
    }

    map<int,int> mapa;

    for(int i=0;i<n;i++)
    {
        mapa[odw[i]]++;
    }
    long long int res=n*(n-1);
    res/=2;
    for(map<int,int>::iterator it=mapa.begin();it!=mapa.end();it++)
    {
        long long int x=it->second;
        res=res-(x*(x-1))/2;
    }

    cout<<res<<endl;
    return 0;
}
