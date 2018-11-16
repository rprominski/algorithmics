#include<iostream>
#include<queue>
#include<map>
#include<vector>
using namespace std;
long long int odw[100010];
int main()
{
    long long int vvv;
    cin>>vvv;
    for(int qqq=0;qqq<vvv;qqq++)
    {
        for(int zzz=0;zzz<100010;zzz++)
            odw[zzz]=0;
        long long int n,m,a,b,sp=1,droga,biblio;
        cin>>n>>m>>biblio>>droga;
        vector<vector<int> > tab;
        tab.resize(n+5);

        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            tab[a].push_back(b);
            tab[b].push_back(a);
        }
        if(biblio<=droga)
            cout<<n*biblio<<endl;

        else
        {
            for(int i=1;i<=n;i++)
            {
                queue<long long int> kol;

                if(odw[i]==0)
                {
                    odw[i]=sp;
                    kol.push(i);

                    while(!kol.empty())
                    {
                        long long int u=kol.front();
                        kol.pop();

                        for(long long int j=0;j<tab[u].size();j++)
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

            map<long long int,long long int> mapa;

            for(int i=1;i<=n;i++)
            {
                mapa[odw[i]]++;
            }
            long long int res=0;
            for(map<long long int,long long int>::iterator it=mapa.begin();it!=mapa.end();it++)
            {
                long long int x=it->second;
                res=res+(x-1)*droga+biblio;
            }

            cout<<res<<endl;
        }
    }
    return 0;
}
