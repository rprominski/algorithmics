#include<iostream>
using namespace std;

string mnozenie(string liczba1, string liczba2)
{
    char wynik[1000010];
    short int a[1000], b[1000], wynik1[1000010];
    for(int i=0;i<1000010;++i)
        wynik1[i]=0;

    for(int i=0;i<liczba1.size();++i)
        a[liczba1.size()-1-i]=liczba1[i]-'0';

    for(int i=0;i<liczba2.size();++i)
        b[liczba2.size()-1-i]=liczba2[i]-'0';

    for(int i=0;i<liczba1.size();++i)
        for(int j=0;j<liczba2.size();++j)
            wynik1[i+j]+=a[i]*b[j];

    int c=0;
    for(int i=0;((i<(liczba1.size()+liczba2.size()-1)) || (c!=0));++i)
    {
        wynik1[i]+=c;
        c=wynik1[i]/10;
        wynik1[i]%=10;
    }
    int size;
    for(int i=1000009;i>0;--i)
        if(wynik1[i]!=0)
        {
            size=i;
            break;
        }

    for(int i=size;i>=0;--i)
        wynik[size-i]=char(wynik1[i]+'0');

    wynik[size+1]='\0';
    return wynik;
}
int main()
{
    string a="12",b="31";

    cout<<mnozenie(a,b)<<endl;
}
