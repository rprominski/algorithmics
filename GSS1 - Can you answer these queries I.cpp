#include<iostream>
using namespace std;
const int N=100000;

struct Node
{
    int left;
    int right;
    int mx;
    int total;

public:
    Node(int x)
    {
        left=x;
        right=x;
        mx=x;
        total=x;
    }
    Node()
    {
    }
};

Node drzewo[2*N+10];
int tab[N+10];
void init(int n, int a, int b)
{
    if(a==b)
    {
        drzewo[n]=Node(tab[a]);
        return;
    }
    int mid=(a+b)/2;

    init(2*n,a,mid);
    init(2*n+1,mid+1,b);

    drzewo[n].left=max(drzewo[2*n].left,drzewo[2*n].total+drzewo[2*n+1].left);
    drzewo[n].right=max(drzewo[2*n+1].right,drzewo[2*n].right+drzewo[2*n+1].total);
    drzewo[n].total=drzewo[2*n].total+drzewo[2*n+1].total;
    drzewo[n].mx=max(drzewo[2*n].mx,max(drzewo[2*n+1].mx,drzewo[2*n].right+drzewo[2*n+1].left));
}

Node odp(long long int n,long long int a,long long int b,long long int x,long long int y)
{
    if(a==x && b==y)
        return drzewo[n];

    long long int mid=(a+b)/2;

    if(y<=mid)
        return odp(2*n,a,mid,x,y);

    else
    {
        if(x>mid)
            return odp(2*n+1,mid+1,b,x,y);

         else
         {
            Node l,p,o;
            l=odp(2*n,a,mid,x,mid);
            p=odp(2*n+1,mid+1,b,mid+1,y);

            o.left=max(l.left,l.total+p.left);
            o.right=max(p.right,l.right+p.total);
            o.total=l.total+p.total;
            o.mx=max(l.mx,max(p.mx,l.right+p.left));
            return o;
         }
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
    long long int n,a,m,b;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>tab[i];
    }

    init(1,0,n-1);
    cin>>m;

    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        cout<<odp(1,0,n-1,a-1,b-1).mx<<endl;
    }
    return 0;
}
