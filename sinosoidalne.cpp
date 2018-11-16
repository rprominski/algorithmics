#include<iostream>
using namespace std;
string szyfruj(string a,int n)
{
    string res="";
    int q=0;
    while(q<a.size())
    {
        res+=a[q];
        q=q+2*(n-1);
    }
    for(int i=1;i<n-1;i++)
    {
        int j=i;
        while(j<a.size())        {
            res+=a[j];
            j=j+2*(n-1-i);

            if(j>=a.size())
                break;
            res+=a[j];

            j=j+i*2;
        }

    }
    q=n-1;
    while(q<a.size())
    {
        res+=a[q];
        q=q+2*(n-1);
    }
    return res;
}
int main()
{
    int t,k;
    string s;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>s>>k;
        if(k==1)
            cout<<s<<endl;
        else
            cout<<szyfruj(s,k)<<endl;
    }



    return 0;
}
