#include<iostream>
using namespace std;
long long int potega(long long int a, long long int b)
{
    long long int c=1;
    while(b>0)
    {
        if(b%2==1)
            c=(c*a)%10;

        b/=2;

        a=(a*a)%10;
    }
    return c;
}
int main()
{

    int t,a,b;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>a>>b;
        cout<<potega(a%10,b)<<endl;
    }

    return 0;
}
