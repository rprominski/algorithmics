#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int tab[t];
    for(int i=0;i<t;i++)
    {
        cin>>tab[i];
    }
    sort(tab,tab+t);

    int res=0;
    for(int i=t-1;i>=0;i--)
    {
        if(tab[i]==tab[t-1])
            res++;
        else
            break;
    }

    cout<<res<<endl;
    return 0;
}
