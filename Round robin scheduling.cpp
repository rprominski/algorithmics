#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int tab2[50006];

struct s
{
    long long t;
    int i;
    bool operator< ( s const &q) const
    {
        return t<q.t;
    }
};
vector<int> vec;

int dodaj(int i)
{
    int w=0;
    while(i>0)
    {
        w+=tab2[i];
        i-= (i&-i);
    }
    return w;
}

void update(int i, int v)
{
    while(i<=50005)
    {
        tab2[i]+=v;
        i+=(i&-i);
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    long long int odp[50006],czas=0,n,m,poz=0;
    s tab[50006];
    cin>>n;
    m=n;

    for (int i=1; i<=n; ++i){
        cin>>tab[i].t;
        tab[i].i=i;
        update(i, 1);
    }

    sort(tab+1, tab+n+1);

    for(int i=1; i<=n; i++)
    {
        if(poz+1 >= tab[i].t)
        {
            int v=tab[i].i;
            odp[v]=czas+dodaj(v);
            vec.push_back(v);
        }
        else
        {
            for(int k=0; k<vec.size(); k++)
                update(vec[k], -1);

            vec.clear();
            czas+=m;
            poz+=1;
            m=dodaj(50005);
            czas+=(tab[i].t-poz-1)*m;
            poz=tab[i--].t-1;
        }
    }

    for(int i=1; i<=n; i++)
        cout<<odp[i]<<endl;
    return 0;
}
