#include<iostream>
using namespace std;
int main()
{
    int n,m;
    string a,b;
    cin>>n>>m;
    int wart[130];
    for(int i=0;i<26;i++)
        cin>>wart['a'+i];






    cin>>a>>b;
    int tab[a.size()+1][b.size()+1];
    for(int i=0;i<=a.size();i++)
        tab[i][0]=0;
    for(int i=0;i<=b.size();i++)
        tab[0][i]=0;

    for(int i=1;i<a.size()+1;i++)
    {
        for(int j=1;j<b.size()+1;j++)
        {
            if(a[i-1]==b[j-1])
            {
                tab[i][j]=max(tab[i-1][j-1]+wart[a[i-1]],max(tab[i-1][j],tab[i][j-1]));
            }
            else
                tab[i][j]=max(tab[i][j-1],tab[i-1][j]);
        }
    }

  /*  for(int i=0;i<=a.size();i++)
    {
        for(int j=0;j<=b.size();j++)
            cout<<tab[i][j]<<" ";
        cout<<endl;
    } */
    cout<<tab[n][m]<<endl;
    return 0;
}
