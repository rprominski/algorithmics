#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
long long int wynik[100010][2];
int main()
{

    int qwerty;
    cin>>qwerty;

    for(int qqq=0;qqq<qwerty;qqq++)
    {

        long long int n,t,a,b,suma=0,suma2=0;
        cin>>n;
        long long int tab[n];
        for(long long int i=0;i<n;i++)
        {
            cin>>tab[i];
        }

        for(int i=0;i<n;i++)
        {
            wynik[i+1][0]=max(wynik[i][0],wynik[i][1]+abs(1-tab[i]));
            wynik[i+1][1]=max(wynik[i][0]+abs(1-tab[i+1]),wynik[i][1]+abs(tab[i]-tab[i+1]));
        }

        cout<<max(wynik[n-1][0],wynik[n-1][1])<<endl;

    }
    return 0;
}
