#include <cmath>
#include<iostream>
using namespace std;
double fibo[100];

int main()
{
    fibo[0]=1;
    fibo[1]=1;

    for(int i=2;i<50;i++)
        fibo[i]=fibo[i-1]+fibo[i-2];

    for(int i=0;i<50;i++)
    {
        if(i%7==0)
            cout<<endl;
        cout<<i<<" "<<int(log(fibo[i]))+1<<endl;

    }
    return 0;
}
