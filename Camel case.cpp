#include<iostream>
using namespace std;
int main()
{
    int res=1;
    string a;
    cin>>a;

    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='A' && a[i]<='Z')
            res++;
    }

    cout<<res<<endl;
    return 0;
}
