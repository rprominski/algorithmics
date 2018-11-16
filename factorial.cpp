#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        vector<vector<pair<int,int> > > tab(n+2);
        for(int j=0;j<n-1;j++)
        {
            int a,b,w;
            cin>>a>>b>>w;
            tab[a].push_back(make_pair(b,w));
            tab[b].push_back(make_pair(a,w));
        }
        int s=1,ma=0,mx=1;
        int odw[n+2];

        for(int j=0;j<n+2;j++)
        {
            odw[j]=-1;
        }

        queue<int> kol;
        kol.push(s);
        odw[s]=0;
        while(!kol.empty())
        {
            int u=kol.front();
            kol.pop();

            for(int j=0;j<tab[u].size();j++)
            {
                int wie=tab[u][j].first;
                int wa=tab[u][j].second;

                if(odw[wie]==-1)
                {
                    kol.push(wie);
                    odw[wie]=odw[u]+wa;

                    if(odw[wie]>ma)
                    {
                        ma=odw[wie];
                        mx=wie;
                    }
                }
            }
        }

        s=mx;

        for(int j=0;j<n+2;j++)
        {
            odw[j]=-1;
        }
        ma=0;
        mx=1;

        kol.push(s);
        odw[s]=0;
        while(!kol.empty())
        {
            int u=kol.front();
            kol.pop();

            for(int j=0;j<tab[u].size();j++)
            {
                int wie=tab[u][j].first;
                int wa=tab[u][j].second;

                if(odw[wie]==-1)
                {
                    kol.push(wie);
                    odw[wie]=odw[u]+wa;

                    if(odw[wie]>ma)
                    {
                        ma=odw[wie];
                        mx=wie;
                    }
                }
            }
        }
        cout<<ma<<endl;
    }

    return 0;
}
