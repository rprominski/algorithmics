#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string s,p;
    int t;
    cin>>t;
    for(int v=0;v<t;v++)
    {
        int M,N;
        int b,pp,i;
        cin>>M;
        cin>>p;
        cin>>s;
        N=s.size();
        int KMPNext[M + 1];
        KMPNext[0] = b = -1;
        for(i = 1; i <= M; i++)
        {
            while((b > -1) && (p[b] != p[i - 1]))
                b = KMPNext[b];
            b++;
            if((i == M) || (p[i] != p[b]))
                KMPNext[i] = b;
            else
                KMPNext[i] = KMPNext[b];
        }

        pp = b = 0;
        for(i = 0; i < N; i++)
        {
            while((b > -1) && (p[b] != s[i]))
                b = KMPNext[b];
            if(++b == M)
            {
              cout<<i-b+1<<endl;
                b = KMPNext[b];
            }
        }
    }
    return 0;
}
