#include<iostream>
#include<vector>
using namespace std;
int main()
{
    long long int t,suma=1,cukierki=1,poczatek,koniec,rosnacy=-1,pom,odp=0;

    cin>>t;
    int tab[t];
    int wynik[t];
    for(int i=0;i<t;i++)
    {
        cin>>tab[i];
    }

    for(int i=0;i<t;i++)
    {
       if(rosnacy==-1)
       {
           if(tab[i]>tab[i-1])
           {
               wynik[i]=wynik[i-1]+1;
           }
           else
           {
               wynik[i]=1;
           }
       }
    }

    for(int i=t-2;i>=0;i--)
    {
        if(tab[i]>tab[i+1])
        {
            pom=wynik[i]+1;
        }
        else pom=1;

        odp=odp+max(pom,wynik[i]);

        wynik[i]=pom;
    }
    cout<<suma<<endl;
    return 0;
}
