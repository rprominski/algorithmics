#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main()
{
    int t,x;
    set<int> result;
    multiset<int> mojset,mojset2;

    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>x;
        mojset.insert(x);
    }

    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>x;
        mojset2.insert(x);
    }

    multiset<int>::iterator it,it2;
    it=mojset.begin();
    it2=mojset2.begin();

    while( it!=mojset.end() && it2!=mojset2.end() )
    {
        if(*it == *it2)
        {
            it++;
            it2++;
        }
        else
        {
            result.insert(*it2);
            it2++;
        }
    }

    while(it2!=mojset2.end())
    {

        result.insert(*it2);
        it2++;
    }
    for(set<int>::iterator iter=result.begin();iter!=result.end();iter++)
    {
        cout<<*iter<<" ";
    }
    return 0;
}
