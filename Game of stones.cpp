#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main()
{
    int x,t;
    int wyniki[110];

    wyniki[1]=2;
    wyniki[2]=1;
    wyniki[3]=1;
    wyniki[4]=1;
    wyniki[5]=1;
    wyniki[6]=1;
    for(int i=7;i<105;i++)
    {
        if(wyniki[i-2]==2 || wyniki[i-3]==2 || wyniki[i-5]==2)
            wyniki[i]=1;
        else
            wyniki[i]=2;
    }

    cin>>t;

    for(int i=0;i<t;i++)
    {
        cin>>x;

        if(wyniki[x]==1)
            cout<<"First"<<endl;
        else
            cout<<"Second"<<endl;
    }
    return 0;
}
