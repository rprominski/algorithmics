#include<bits/stdc++.h>
using namespace std;
const int N=524288;
int drzewo[N*2+1];
void insert(int a,int b)
{
    a=N+a;
    drzewo[a]=b;
    a/=2;
    while(a>0)
    {
        int left=2*a,right=left+1;
        drzewo[a]=max(drzewo[left],drzewo[right]);
        a/=2;
    }
}

int findMax(int a,int b)
{
    a+=N; b+=N;

    int wynik=max(drzewo[a],drzewo[b]);

    while(a/2 != b/2)
    {
        if(a%2==0)
            wynik=max(wynik,drzewo[a+1]);
        if(b%2==1)
            wynik=max(wynik,drzewo[b-1]);

        a/=2; b/=2;
    }

    return wynik;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n,m,a,b,x;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>a>>b;
        if(x==1)
        {
            insert(a,b);
        }
        else
        {
            cout<<findMax(a,b)<<endl;
        }
    }

   /* for(int i=0;i<N*2;i++)
    {
        cout<<i<<" "<<drzewo[i]<<endl;
    } */
    return 0;
}
