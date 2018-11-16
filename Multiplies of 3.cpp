#include <iostream>
using namespace std;
const int N = 100001;
int n, q, lazy[4*N];
pair<int,int>  t[4*N];

void lazy_update(int k, int l, int r)
{
    lazy[k] %= 3;
    int s0=t[k].first;
    int s1=t[k].second;
    int s2=(r-l+1)-s0-s1;
    if (lazy[k] == 0)
        return;

    if (lazy[k] == 1)
    {
        t[k].first=s2;
        t[k].second=s0;
    }
    else
    {
        t[k].first=s1;
        t[k].second=s2;
    }
    if (l < r)
    {
        lazy[k*2]+=lazy[k];
        lazy[k*2+1]+=lazy[k];
    }
    lazy[k]=0;
}

pair<int,int> combine(pair<int,int> u, pair<int,int> v)
{
    pair<int,int> ans;
    ans.first=u.first+v.first;
    ans.second=u.second+v.second;
    return ans;
}

void build(int k, int l, int r)
{
    if (l == r)
    {
        t[k]=make_pair(1,0);
        return;
    }
    int mid=(l+r)/2;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    t[k]=combine(t[k*2],t[k*2+1]);
}

void update(int k, int l, int r, int L, int R)
{
    lazy_update(k,l,r);
    if (r < L || R < l)
        return ;
    if (L <= l && r <= R)
    {
        lazy[k]++;
        lazy_update(k,l,r);
        return ;
    }
    int mid=(l+r)/2;
    update(k*2,l,mid,L,R);
    update(k*2+1,mid+1,r,L,R);
    t[k]=combine(t[k*2], t[k*2+1]);
}

pair<int,int> get(int k, int l, int r, int L, int R)
{
    lazy_update(k,l,r);

    if (r < L || R < l)
        return make_pair(0,0);

    if (l == L && r == R)
        return t[k];

    int mid =(l+r)/2;

    if (mid < L)
        return get(k*2+1,mid+1,r,L,R);

    if (R < mid+1)
        return get(k*2,l,mid,L,R);

    return combine(get(k*2,l,mid,L,mid),get(k*2+1,mid+1,r,mid+1,R));
}

int main()
{
    cin>>n>>q;
    build(1,1,n);
    for(int i=0;i<q;i++)
    {
        int typ, l, r;
        cin>>typ>>l>>r;

        if (typ==0)
            update(1,1,n,l+1,r+1);

        else
            cout<<get(1,1,n,l+1,r+1).first<<endl;
    }

    return 0;
}
