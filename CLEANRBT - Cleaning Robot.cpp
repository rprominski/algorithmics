#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

int n,m;
char tab[30][30];
int odl[30][30];
vector<pair<int,int> > vec;
map<pair<int,int>,int> numery;

bool ok(int x,int y)
{
    if(x<0 || y<0 || x>=m || y>=n || tab[x][y]=='x')
        return false;

    return true;
}

void bfs(pair<int,int> p)
{
    int odw[30][30];
    int num=numery[p];

    for(int i=0;i<30;i++)
    {
        for(int j=0;j<30;j++)
            odw[i][j]=-1;
    }
    odw[p.first][p.second]=0;
    queue<pair<int,int> > kol;
    kol.push(p);

    while(!kol.empty())
    {
        int ux=kol.front().first;
        int uy=kol.front().second;


        if(tab[ux][uy]=='*')
        {
            int num2=numery[kol.front()];
            odl[num][num2]=odw[ux][uy];
            odl[num2][num]=odw[ux][uy];
        }
        kol.pop();
        if(ok(ux+1,uy) && odw[ux+1][uy]==-1)
        {
            odw[ux+1][uy]=odw[ux][uy]+1;
            kol.push(make_pair(ux+1,uy));
        }
        if(ok(ux,uy-1) && odw[ux][uy-1]==-1)
        {
            odw[ux][uy-1]=odw[ux][uy]+1;
            kol.push(make_pair(ux,uy-1));
        }
        if(ok(ux,uy+1) && odw[ux][uy+1]==-1)
        {
            odw[ux][uy+1]=odw[ux][uy]+1;
            kol.push(make_pair(ux,uy+1));
        }
        if(ok(ux-1,uy) && odw[ux-1][uy]==-1)
        {
            odw[ux-1][uy]=odw[ux][uy]+1;
            kol.push(make_pair(ux-1,uy));
        }
    }
}
int main()
{
    while(cin>>n>>m)
    {
        if(n==0 || m==0)
            break;

        for(int zz=0;zz<30;zz++)
        {
            for(int zzz=0;zzz<30;zzz++)
                odl[zz][zzz]=1000000;
        }
        vec.clear();
        numery.clear();

        pair<int,int> start;
        int num=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>tab[i][j];
                if(tab[i][j]=='*')
                {
                    vec.push_back(make_pair(i,j));
                    numery[make_pair(i,j)]=num;
                    num++;
                }
                if(tab[i][j]=='o')
                {
                    numery[make_pair(i,j)]=0;
                    vec.push_back(make_pair(i,j));
                }
            }
        }

        for(int zzz=0;zzz<vec.size();zzz++)
            bfs(vec[zzz]);

        vector<int> perm;
        for(int i=1;i<num;i++)
            perm.push_back(i);

        int mn=1000000000;
        do
        {
            int res=0;
            res+=odl[0][perm[0]];
            for(int i=0;i<perm.size()-1;i++)
            {
                res+=odl[perm[i]][perm[i+1]];
            }
            mn=min(mn,res);
        }while(next_permutation(perm.begin(),perm.end()));

        if(mn>100000)
            mn=-1;

        cout<<mn<<endl;
    }

    return 0;
}
