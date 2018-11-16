#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int t,a;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>a;

        int piatki=-1,trojki=-1,j=0;
        while(a>=3*j)
        {
            if((a-3*j)%5==0)
            {
                piatki=j*3;
                trojki=a-piatki;
            }
                j++;
        }
        if(piatki==-1 && trojki==-1)
            cout<<-1<<endl;
        else
        {
            for(int q=0;q<piatki;q++)
                cout<<5;
            for(int q=0;q<trojki;q++)
                cout<<3;
            cout<<endl;
        }
    }


    return 0;
}

