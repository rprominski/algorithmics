#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int nwd(int x,int y)
{
    int r=1;
    while(r!=0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int main()
{

    int t,a,b,c;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>a>>b>>c;
        cout<<"Case "<<i+1<<": ";
        if(c%nwd(a,b)==0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

    return 0;
}
