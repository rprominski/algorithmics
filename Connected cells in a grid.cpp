#include<iostream>
#include<queue>
#include<map>
#include<vector>
using namespace std;
int odw[100][100],xx,yy;
int tab[100][100];
bool good(int x,int y)
{
    if(x<0 || y<0 || x>=xx || y>= yy)
        return false;

    return true;
}
void dfs(int x,int y)
{
    if(good(x-1,y))
    {
        if(odw[x-1][y]==0)
        {
            if(tab[x-1][y]==0)
            {
                odw[x-1][y]=-1;
            }
            else
            {
                odw[x-1][y]=odw[x][y];
                dfs(x-1,y);
            }
        }
    }

    if(good(x,y+1))
    {
        if(odw[x][y+1]==0)
        {
            if(tab[x][y+1]==0)
            {
                odw[x][y+1]=-1;
            }
            else
            {
                odw[x][y+1]=odw[x][y];
                dfs(x,y+1);
            }
        }
    }

    if(good(x,y-1))
    {
        if(odw[x][y-1]==0)
        {
            if(tab[x][y-1]==0)
            {
                odw[x][y-1]=-1;
            }
            else{
            odw[x][y-1]=odw[x][y];
            dfs(x,y-1);

        }}
    }

    if(good(x+1,y))
    {
        if(odw[x+1][y]==0)
        {
            if(tab[x+1][y]==0)
            {
                odw[x+1][y]=-1;
            } else{
            odw[x+1][y]=odw[x][y];
            dfs(x+1,y); }
        }
    }
    ///////////////////////////////////////////gh
    if(good(x+1,y-1))
    {
        if(odw[x+1][y-1]==0)
        {
            if(tab[x+1][y-1]==0)
            {
                odw[x+1][y-1]=-1;
            } else{
            odw[x+1][y-1]=odw[x][y];
            dfs(x+1,y-1); }
        }
    }

    if(good(x+1,y+1))
    {
        if(odw[x+1][y+1]==0)
        {
            if(tab[x+1][y+1]==0)
            {
                odw[x+1][y+1]=-1;
            } else{
            odw[x+1][y+1]=odw[x][y];
            dfs(x+1,y+1); }
        }
    }

    if(good(x-1,y-1))
    {
        if(odw[x-1][y-1]==0)
        {
            if(tab[x-1][y-1]==0)
            {
                odw[x-1][y-1]=-1;
            } else{
            odw[x-1][y-1]=odw[x][y];
            dfs(x-1,y-1); }
        }
    }

    if(good(x-1,y+1))
    {
        if(odw[x-1][y+1]==0)
        {
            if(tab[x-1][y+1]==0)
            {
                odw[x-1][y+1]=-1;
            } else{
            odw[x-1][y+1]=odw[x][y];
            dfs(x-1,y+1); }
        }
    }
}
int main()
{
    int t,n,m,sp=2;
    cin>>n>>m;
    xx=n;
    yy=m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>tab[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(odw[i][j]==0 && tab[i][j]==1)
            {
                odw[i][j]=sp;
                dfs(i,j);
                sp++;
            }
        }
    }

    map<int,int> res;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            res[odw[i][j]]++;
        }
    }
    int mx=-1;
    for(map<int,int>::iterator it=res.begin();it!=res.end();it++)
    {
        if(it->first>0)
            mx=max(mx,it->second);
    }

    cout<<mx<<endl;
    return 0;
}
