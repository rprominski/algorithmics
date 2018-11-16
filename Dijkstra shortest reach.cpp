#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<fstream>
using namespace std;
int waga[3010],inf=1000000000;
struct cmp
{
    bool operator()(const int &a, const int &b)
    {
        if(waga[a]<waga[b])
            return true;
        if(waga[a]>waga[b])
            return false;

        return a<b;
    }
};
int main()
{
    ofstream wyj("wynik.txt");
    long long int t,n,a,b,w,s,m;
    cin>>t;
    for(int i=0;i<t;i++)
    {

        for(int j=0;j<3010;j++)
            waga[j]=inf;

        cin>>n>>m;
        set<int,cmp> kopiec;
        vector< vector< pair<int,int> > > tab;
        tab.resize(n+2);
        for(int j=0;j<m;j++)
        {
            cin>>a>>b>>w;
            tab[a].push_back(make_pair(b,w));
            tab[b].push_back(make_pair(a,w));
        }
        int odw[n+10];
        for(int j=0;j<n+5;j++)
            odw[j]=0;

        cin>>s;
        odw[s]=1;
        waga[s]=0;

        for(int j=1;j<=n;j++)
            kopiec.insert(j);
        while(kopiec.size()>0)
        {

            int u= *(kopiec.begin());

            kopiec.erase(kopiec.begin());

            for(int j=0;j<tab[u].size();j++)
            {

                int fi=tab[u][j].first;
                int se=tab[u][j].second;

                if(waga[u]+se<waga[fi])
                {

                    kopiec.erase(kopiec.find(fi));

                    waga[fi]=waga[u]+se;
                    kopiec.insert(fi);
                }
            }
        }

        for(int j=1;j<=n;j++)
        {
            if(j!=s)
            {
                if(waga[j]==inf)
                    wyj<<-1<<" ";
                else
                    wyj<<waga[j]<<" ";
            }

        }
        wyj<<endl;
    }

    return 0;
}
