#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

bool ok(int x,int y,int n,int m)
{
    if(x<0 || y <0 || x>=n || y>=m)
        return false;

    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int q;
    cin>>q;
    for(int vvv=0;vvv<q;vvv++)
    {
        long long int n,m,mx=-1;
        pair<long long int,long long int> para, parmax;
        cin>>n>>m;
        char tab[m][n];
        int odl[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>tab[i][j];
                odl[i][j]=-1;
                if(tab[i][j]=='.')
                {
                    para=make_pair(i,j);
                    parmax=make_pair(i,j);
                }
            }
        }

        odl[para.first][para.second]=0;

        queue< pair<long long int,long long int> > kol;
        kol.push(para);

        while(!kol.empty())
        {
            long long int xx=kol.front().first,yy=kol.front().second;
            kol.pop();

            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            for (int i = 0; i < 4; i++)
            {
                int x2 = xx+dx[i], y2 = yy+dy[i];
                if (odl[x2][y2]==-1 && tab[x2][y2]=='.' && ok(x2,y2,m,n))
                {
                    odl[x2][y2]=odl[xx][yy]+1;
                    if(odl[x2][y2]>mx)
                    {
                        mx=odl[x2][y2];
                        parmax=make_pair(x2,y2);
                    }
                    kol.push(make_pair(x2,y2));
                }
            }

        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                odl[i][j]=-1;
            }
        }

        mx=0;
        odl[parmax.first][parmax.second]=0;
        kol.push(parmax);

        while(!kol.empty())
        {
            long long int xx=kol.front().first,yy=kol.front().second;
            kol.pop();

            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            for (int i = 0; i < 4; i++)
            {
                int x2 = xx+dx[i], y2 = yy+dy[i];
                if (odl[x2][y2]==-1 && tab[x2][y2]=='.' && ok(x2,y2,m,n))
                {
                    odl[x2][y2]=odl[xx][yy]+1;
                    if(odl[x2][y2]>mx)
                    {
                        mx=odl[x2][y2];
                        parmax=make_pair(x2,y2);
                    }
                    kol.push(make_pair(x2,y2));
                }
            }

        }

        cout<<"Maximum rope length is "<<mx<<"."<<endl;
            /*
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<odl[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<parmax.first<<" "<<parmax.second<<endl; */
    }



    return 0;
}
