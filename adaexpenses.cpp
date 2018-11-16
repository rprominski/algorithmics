#include<iostream>
using namespace std;
long long int modulo[229010];
void wypelnij()
{
    modulo[0]=0;
    for(int i=1;i<229000;i++)
        modulo[i]=(modulo[i-1]*1000000000+111111111)%1000000007;
}

long long int dopelnienie(long long int x, long long int co)
{

    if(x==0)
        return co;
    if(x==1)
        return (co*10+1)%1000000007;
    if(x==2)
        return (co*100+11)%1000000007;
    if(x==3)
        return (co*1000+111)%1000000007;
    if(x==4)
        return (co*10000+1111)%1000000007;
    if(x==5)
        return (co*100000+11111)%1000000007;
    if(x==6)
        return (co*1000000+111111)%1000000007;
    if(x==7)
        return (co*10000000+1111111)%1000000007;
    if(x==8)
        return (co*100000000+11111111)%1000000007;
}
int main()
{
    wypelnij();
    string s;
    cin>>s;
    long long int res=0,mn,j=0;
    for(int i=s.size()-1;i>=0;i--)
    {
        mn=s[i]-'0';

        mn*=(s.size()-j);
        res=res+mn*(dopelnienie((j+1)%9,modulo[(j+1)/9]));

        res%=1000000007;
        j++;
    }
    cout<<res<<endl;
    return 0;
}
