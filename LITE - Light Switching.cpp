#include<iostream>
using namespace std;
long long int drzewo[1000010];
long long int leniwaPropagacja[1000010];
void aktualizuj(int n,int a,int b,int x,int y)
{

    if(leniwaPropagacja[n])
    {
        leniwaPropagacja[n]=0;
        drzewo[n]=b-a+1-drzewo[n];
        if(a!=b)
        {
            leniwaPropagacja[2*n]=!leniwaPropagacja[2*n];
            leniwaPropagacja[2*n+1]=!leniwaPropagacja[2*n+1];
        }
    }

    if(x>b || y<a || a>b)
        return;

    if(a>=x && b<=y)
    {
        drzewo[n]=b-a+1-drzewo[n];

        if(a!=b)
        {
            leniwaPropagacja[2*n]=!leniwaPropagacja[2*n];
            leniwaPropagacja[2*n+1]=!leniwaPropagacja[2*n+1];
        }
        return;
    }

        long long int mid=(a+b)/2;
        aktualizuj(n*2,a,mid,x,y);
        aktualizuj(n*2+1,mid+1,b,x,y);
        drzewo[n]=drzewo[2*n]+drzewo[2*n+1];

}

int odp(long long int n,long long int a,long long int b,long long int x,long long int y)
{
    if(leniwaPropagacja[n])
    {
        leniwaPropagacja[n]=0;
        drzewo[n]=b-a+1-drzewo[n];
        if(a!=b)
        {
            leniwaPropagacja[2*n]=!leniwaPropagacja[2*n];
            leniwaPropagacja[2*n+1]=!leniwaPropagacja[2*n+1];
        }
    }

    if(a>=x && b<=y)
        return drzewo[n];

    long long int mid=(a+b)/2;

    if(y<=mid)
        return odp(2*n,a,mid,x,y);

    if(x>mid)
        return odp(2*n+1,mid+1,b,x,y);

    return odp(2*n,a,mid,x,y)+odp(2*n+1,mid+1,b,x,y);
}
int main()
{
    long long int n,m,q,a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>q>>a>>b;
        if(q==0)
        {
            aktualizuj(1,0,n-1,a-1,b-1);
        }
        else
        {
            cout<<odp(1,0,n-1,a-1,b-1)<<endl;
        }
    }
	return 0;
}
