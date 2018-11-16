#include<iostream>
using namespace std;
const int n=10000000;

int pierwsze[n+10];
long long int odp[n+10];

void sito()
{
    for(int i=2;i<=n;i++)
    {
        if(pierwsze[i]==0)
        {
            for(int j=i*2;j<=n;j+=i)
            {
                if(pierwsze[j]==0)
                    pierwsze[j]=i;
            }

            odp[i]=odp[i-1]+i;
        }
        else
        {
            odp[i]=odp[i-1]+pierwsze[i];
        }
    }
}

int main()
{
    sito();
    long long int t,a;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        cin>>a;
        cout<<odp[a]<<endl;
    }

}
