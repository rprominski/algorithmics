#include<iostream>
using namespace std;
const int n=1000000;
bool wyniki[n+1];
void generuj()
{
    wyniki[1]=0;
    for(int i=2;i<=n;i++)
    {
        bool q=0;

        for(int j=1;j*j<=i;j++)
        {
          //  cout<<i<<" "<<j<<endl;
            if(i%j==0)
            {
                if(wyniki[i-j]==0)
                {
                    q=1;
                    break;
                }
                if(wyniki[i-i/j]==0)
                {
                    if(j==1)
                        continue;

                    q=1;
                    break;
                }
            }
        }
        if(q==1)
            wyniki[i]=1;
        else
            wyniki[i]=0;
    }
}
int main()
{
  //  generuj();
    int t,a;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        cin>>a;
        if(a%2==0)
            cout<<"Thankyou Shaktiman"<<endl;
        else
            cout<<"Sorry Shaktiman"<<endl;
    }
   /* for(int i=0;i<t;i++)
    {
        a=i+1;
        if(wyniki[a]==0)
            cout<<"Sorry Shaktiman"<<endl;
        else
            cout<<"Thankyou Shaktiman"<<endl;
    }*/

  //  for(int i=0;i<300;i++)
   //     cout<<i<<" "<<wyniki[i]<<endl;




    return 0;
}
