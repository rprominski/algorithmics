#include<iostream>
using namespace std;
int dwojki(int t)
{
    int d=2,res=0;
    while(d<=t)
    {
        res+=t/d;
        d*=2;
    }
    return res;
}
int main()
{
    int t,n,licznik;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        licznik=dwojki(n);
        int res=0;
        for(int i=0;i*2<=n;i++)
        {
            if(licznik-dwojki(i)-dwojki(n-i)>=2)
                res+=2;
        }
        if(n%2==0)
            if(licznik-dwojki(n/2)-dwojki(n/2)>=2)
                res--;
        cout<<res<<endl;
    }
    return 0;
}
