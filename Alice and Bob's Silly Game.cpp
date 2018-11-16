#include<iostream>
#include<vector>
using namespace std;
int n=100005;
bool pierwsza[100010];
int res[100010];
vector<int> pierwsze;
void sito(int n)
{
    for(int i=2;i<=n-1;i++)
    {
        if(!pierwsza[i])
        {
            pierwsze.push_back(i);
            for(int j=i;j<=n-1;j+=i)
                pierwsza[j]=true;
        }
    }
}

int main()
{
    sito(n);
    int j=0,t,v;
    for(int i=1;i<=100001;i++)
    {
        if(pierwsze[j]==i)
        {
             j++;
            res[i]=res[i-1]+1;
        }
        else
            res[i]=res[i-1];

    }
    cin>>t;

    for(int i=0;i<t;i++)
    {
        cin>>v;
        if(res[v]%2==0)
            cout<<"Bob"<<endl;
        else
            cout<<"Alice"<<endl;
    }

    return 0;
}
