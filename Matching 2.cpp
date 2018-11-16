#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int n,nw;
int skoj[100010];
int vis[100010];
vector< vector<int> > tab;
bool dfs(int v)
{
    vis[v]=true;

    for(int i=0;i<tab[v].size();i++)
    {
        int x=tab[v][i];
        if (skoj[x]==-1 || (!vis[skoj[x]] && dfs(skoj[x])))
        {
            skoj[v]=x; skoj[x]=v;
            return true;
        }
    }

    return false;
}

void kojarz()
{
    for(int i=1;i<n+1;i++)
        skoj[i]=-1;
    for(int v=1;v<=nw;v++)
    {
        for(int i=1;i<=nw;i++)
            vis[i]=false;
        dfs(v);
    }
}

int main()
{
   // ios_base::sync_with_stdio(0);
    int a,b,c,x,y,z;
    scanf("%d%d%d",&a,&b,&c);
    n=a+b;
    tab.resize(n+1);
    nw=b;
    for(int i=0;i<c;i++)
    {
        cin>>x>>y;
        tab[x].push_back(y+a);
       // tab[y].push_back(x+b);
    }
    kojarz();
    int wyn=0;
    for(int i=0;i<=a;i++)
    {
        if(skoj[i]!=0 && skoj[i]!=-1)
            wyn++;
    }
    printf("%d",wyn);
    return 0;
}
