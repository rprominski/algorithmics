#include<iostream>
using namespace std;
string result(int t)
{

    t-=2;
    t%=20;
    if(t==0 || t==9 || t==10 || t==19)
        return "W L";

    if(t==1 || t==8 || t==11 || t==18)
        return "A L";

    if(t==2 || t==7 || t==12 || t==17)
        return "A R";

    if(t==3 || t==6 || t==13 || t==16)
        return "M";

    return "W R";
}
int main()
{
    int n,m,t;
    string a,b;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>t;
        if(t==1)
        {
            cout<< "poor conductor"<<endl;
            continue;
        }
        if((t-1)%5==0)
            cout<<(t-1)/5<<" ";
        else
            cout<<(t-1)/5+1<<" ";
        cout<<result(t)<<endl;
    }
    return 0;
}
