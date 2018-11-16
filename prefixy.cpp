#include<iostream>
#include<vector>
#include<set>
using namespace std;

struct data
{
    string prefix;
    int number;
    bool operator< ( data const &q) const {return prefix < q.prefix;}
};
int main()
{
    string a;
    set<data> myset;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        data d;
        d.number=i;
        d.prefix=a.substr(i);
        myset.insert(d);
    }
    int tab[a.size()+10],i=1,n,b;
    for(set<data>::iterator it=myset.begin();it!=myset.end();it++)
    {
      //  cout<<it->prefix<<" "<<it->number<<endl;
        tab[i]=it->number;
        i++;
    }
    cin>>n;
    for(int j=0;j<n;j++)
    {
        cin>>b;
        cout<<tab[b]<<endl;

    }
    return 0;
}

