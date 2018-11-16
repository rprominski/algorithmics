#include<iostream>
using namespace std;
char rotuj(char z,int k)
{

    if(z>='A' && z<='Z')
    {
        if(z+k<='Z')
            return char (z+k);

        else
            return 'A'+((z+k)%'Z');
    }

    if(z>='a' && z<='z')
    {
        if(z+k<='z')
            return char (z+k);

        else
            return 'a'+((z+k)%'z'-1);
    }

    return z;
}
string szyfr(string tekst,int x)
{
    for(int i=0;i<=tekst.length();i++){
    if(tekst[i]>=65 && tekst[i]<=90-x) tekst[i]=int(tekst[i])+x; //wielkie liter
    else if(tekst[i]>=91-x && tekst[i]<=90) tekst[i]=int(tekst[i])-26+x; // wielkie litery
    else if(tekst[i]>=97 && tekst[i]<=122-x) tekst[i]=int(tekst[i])+x; //ma³e liter
    else if(tekst[i]>=123-x && tekst[i]<=122) tekst[i]=int(tekst[i])-26+x; //ma³e litery
    }

    return tekst;
}
int main()
{
    int res=1,t,k;
    string a,ak,ak2;
    cin>>t;
    cin>>a;
    cin>>k;


    k%=26;

    cout<<szyfr(a,k)<<endl;
  //  for(int i=0;i<t;i++)
  ///  {
  //      a[i]=rotuj(a[i],k);
  //  }




    return 0;
}
