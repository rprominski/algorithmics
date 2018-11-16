#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;

string newString(string a, char x, char y)
{
    string res="";
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==x || a[i]==y)
            res+=a[i];
    }

    return res;
}

bool isGood(string a)
{
    for(int i=0;i<a.size()-1;i++)
        if(a[i]==a[i+1])
            return false;

    return true;
}

int main()
{
    int t,m=0;
    string a;
    cin>>t;
    cin>>a;

    if(a.size()!=t)
    {
        while(1)
        {

        }
    }
    for(int i='a';i<='y';i++)
    {
        for(int j=i+1;j<='z';j++)
        {
            string pom=newString(a,char(i),char(j));
            if(isGood(pom))
                m=max(m,int(pom.size()));
        }
    }

    cout<<m<<endl;
    return 0;
}
