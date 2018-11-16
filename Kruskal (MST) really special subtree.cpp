#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<exception>
using namespace std;
struct str
{
    int a;
    int b;
    int w;

    str(int x,int y,int z)
    {
        a=x;
        b=y;
        w=z;
    }
};
bool operator<(const str &x, const str &y)
{
    if(x.w<y.w)
        return true;
    if(x.w>y.w)
        return false;
    if(x.w+x.a+x.b<y.w+y.b+y.a)
        return true;
    else
        return false;
}
int main()
{
    set<str> mojset;
    long long int n,m,a,b,w,sp=1,suma=0,cap;
    vector< vector<long long int> > tab;
    cin>>n>>m;
    int spojna[n+2];
    tab.resize(1008);
    for(int i=1;i<=n;i++)
    {
        spojna[i]=-1;
    }
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>w;
        mojset.insert(str(a,b,w));
    }
    int zzz=0;
    for(set<str>::iterator it=mojset.begin();it!=mojset.end();it++)
    { //cout<<zzz++<<endl; cap=0;
        cap=0;
        for(int xx=0;xx<=n;xx++)
        {
         //   cout<<xx<<" "<<tab[xx].capacity()<<endl;
           cap+=tab[xx].capacity();
        }
  //      cout<<cap<<endl;
        a=it->a;
        b=it->b;
        w=it->w;

        if(spojna[a]==-1 && spojna[b]==-1)
        {
            spojna[a]=sp;
            spojna[b]=sp;
            tab[sp].push_back(a);
            tab[sp].push_back(b);
            suma+=w;
            sp++;
        }
        else
        {
            if(spojna[a]==-1 && spojna[b]!=-1)
            {
                spojna[a]=spojna[b];
                tab[spojna[b]].push_back(a);
                suma+=w;
                sp++;
            }
            else
            {
                if(spojna[b]==-1 && spojna[a]!=-1)
                {
                    spojna[b]=spojna[a];
                    tab[spojna[a]].push_back(b);
                    suma+=w;
                }
                else
                {
                    if(spojna[a]!=spojna[b])
                    {   long long int x=tab[spojna[b]].size();
                        long long int v=spojna[b];
                        for(int q=0;q<x;q++)
                        //    cout<<tab[spojna[b]][q]<<endl;
                        for(int j=0;j<x;j++)
                        { //cout<<a<<" "<<spojna[a]<<" "<<b<<" "<<spojna[b]<<endl;
                            if(spojna[tab[v][j]]!=spojna[a])
                                tab[spojna[a]].push_back(tab[v][j]);
                            spojna[tab[v][j]]=spojna[a];
                        }

                       // for(int asd=0;asd<tab[spojna[a]].size();asd++)
                           // cout<<asd<<" "<<tab[spojna[a]][asd]<<endl;
                        tab[v].clear();
                         suma+=w;
                    }
                }
            }
        }
  //      for(int q=0;q<=n;q++)
      //      cout<<q<<" "<<spojna[q]<<endl;
    //    cout<<endl;
    }
    cout<<suma<<endl;
    return 0;
}
