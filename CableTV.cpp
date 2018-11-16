#include<iostream>
#include<vector>
#include<exception>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,m;
    cin>>t;
    try{
    for(int i=0;i<t;i++)
    {
        cin>>n>>m;
        vector<vector<int> > tab(n+10);
        int mi=0;
        for(int j=0;j<m;j++)
        {
            char z;
            int a,b;
            cin>>z>>a>>z>>b>>z;
            mi=max(mi,max(a,b));
            tab[a].push_back(b);
            tab[b].push_back(a);
        }

        int minx=10000000;
        for(int q=0;q<=mi;q++)
        {
            if(tab[q].size()<minx)
                minx=tab[q].size();
        }
        if(m==0 && n==0)
        {
            cout<<0<<endl;
            continue;
        }

        if(minx==n-1)
            cout<<n<<endl;
        else
            cout<<minx<<endl;

    }
    }catch(exception &ex){
        cout<<ex.what()<<endl;
    }
    return 0;
}
