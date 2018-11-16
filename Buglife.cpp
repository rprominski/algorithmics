#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int odw[2500];
int ojc[2500];
vector<vector<int> > tab;
bool dfs(int source)
{
    for(int i=0;i<tab[source].size();i++)
    {

        if(odw[source]==odw[tab[source][i]])
            return false;

        if(odw[tab[source][i]]==0)
        {
            odw[tab[source][i]]=-odw[source];
            dfs(tab[source][i]);
        }
    }

    return true;
}
int main()
{
    int t;
    cin>>t;

    for(int i=0;i<t;i++)
    {

        for(int v=0;v<2500;v++)
        {
            odw[v]=0;
            ojc[v]=0;
        }
        int n,m,a,b;
        cin>>n>>m;

        tab.clear();
        tab.resize(n+3);

        for(int j=0;j<m;j++)
        {
            cin>>a>>b;
            tab[a].push_back(b);
            tab[b].push_back(a);
        }

        bool q=1;
        for(int j=1;j<=n;j++)
        {
            if(odw[j]==0)
            {
                odw[j]=1;
                if(!dfs(j))
                {
                    q=0;
                    break;
                }
            }
        }
        cout<<"Scenario #"<<i+1<<":"<<endl;

        if(q)
            cout<<"No suspicious bugs found!"<<endl;
        else
            cout<<"Suspicious bugs found!"<<endl;
    }

    return 0;
}
