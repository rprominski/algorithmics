#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int maxN=201;
int ojc[maxN];
bool odw[maxN];
vector<vector<int> > tab(maxN);
int rezyd[maxN][maxN];
int poj[maxN][maxN];

bool bfs(int v,int s)
{
    for(int i=0;i<maxN;i++)
    {
        ojc[i]=-1;
        odw[i]=0;
    }

    queue<int> kol;
    odw[s]=1;
    ojc[s]=-1;
    kol.push(s);

    while(!kol.empty())
    {
        int u=kol.front();
        kol.pop();
        if(u==v)
            break;
        for(int i=1;i<=v;i++)
        {
            if(odw[i]==0 && rezyd[u][i]>0)
            {
                kol.push(i);
                ojc[i]=u;
                odw[i]=1;
            }
        }
    }
    int i=v;
    while(i!=-1)
    {
        rezyd[ojc[i]][i]--;
        rezyd[i][ojc[i]]++;
        i=ojc[i];
    }

    if(odw[v])
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int l;
    cin>>l;
    for(int q=0;q<l;q++)
    {
        for(int i=0;i<maxN;i++)
        {
            tab[i].clear();
            for(int j=0;j<maxN;j++)
                rezyd[i][j]=0,poj[i][j]=0;
        }

        int a,n,m,odp=0;;
        cin>>m;
        for(int i=1;i<m;i++)
        {
            cin>>n;
            for(int j=0;j<n;j++)
            {
                cin>>a;
                tab[i].push_back(a);
                if(a==m || i==1)
                    rezyd[i][a]=1;
                else
                    rezyd[i][a]=1000000;
            }
        }
        while(bfs(m,1))
        {
            odp++;
        }
        cout<<odp<<endl;
    }
    return 0;
}
