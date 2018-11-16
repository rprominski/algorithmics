#include<iostream>
#include<map>

using namespace std;
long long int parse(string x)
{
    long long int wynik=0,mn=1;
    for(int i=x.size()-1;i>=0;i--)
    {
        if(x[i]>='0' && x[i]<='9')
        {
            while(1)
            {
                if(!(x[i]>='0' && x[i]<='9'))
                    return wynik;

                wynik+=((x[i]-'0')*mn);
                mn*=10;
                i--;
            }
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n,ac,r,qwerty=1;

    while(cin>>n>>ac>>r)
    {
        long long int licznik=1;
        if(n==0 && ac==0 && r==0)
            break;

        string str,garaz,a,b,c;
        cin>>garaz;

        map<string,int> mapa;
        mapa[garaz]=0;

        string tab[ac];
        for(int i=0;i<ac;i++)
        {
            cin>>tab[i];
        }

        int abc=100;
        long long int odl[abc][abc];
        for(int i=0;i<abc;i++)
            for(int j=0;j<abc;j++)
            {
                odl[i][j]=2000000000;
                if(i==j)
                    odl[i][j]=0;
            }
        for(int i=0;i<r;i++)
        {
            cin>>a>>b>>c;
            if(mapa[a]==0 && a!=garaz)
            {
                mapa[a]=licznik;
                licznik++;
            }
            if(mapa[c]==0 && c!=garaz)
            {
                mapa[c]=licznik;
                licznik++;
            }
            long long int o=parse(b);
            long long int ma=mapa[a],mc=mapa[c];
            if(b[b.size()-1]=='>' && b[0]=='<')
            {

                odl[ma][mc]=min(o,odl[ma][mc]);
                odl[mc][ma]=min(o,odl[mc][ma]);
            }
            else
            {
                if(b[0]=='<')
                {
                     odl[mc][ma]=min(o,odl[mc][ma]);
                }
                else
                {
                    odl[ma][mc]=min(o,odl[ma][mc]);
                }
            }

        }

        for (int k = 0; k < licznik; k++)
            for (int i = 0; i < licznik; i++)
                for (int j = 0; j < licznik;j++)
                    odl[i][j] = min(odl[i][j],odl[i][k]+odl[k][j]);

        long long int wynik=0;
        for(int i=0;i<ac;i++)
        {
            wynik+=odl[mapa[tab[i]]][0]+odl[0][mapa[tab[i]]];
        }
        cout<<qwerty<<". "<<wynik<<endl;
      /*  for(int i=0;i<licznik;i++)
        {
            for(int j=0;j<licznik;j++)
            {
                cout<<odl[i][j]<<" ";
            }
            cout<<endl;
        }

        for(map<string,int>::iterator it=mapa.begin();it!=mapa.end();it++)
        {
            cout<<it->first<<" "<<it->second<<endl;
        } */

    qwerty++;
    }

    return 0;
}
