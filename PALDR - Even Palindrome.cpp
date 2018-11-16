#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int V;
    cin>>V;
    for(int q=0;q<V;q++)
    {
        string s;
        cin>>s;
        int N = s.size();
        s="#"+s+"$";
        int R[s.size()];
        int i = 1;
        int t = 0;

        R[0] = 0;
        while(i <= N)
        {
            while(s[i-t] == s[i + t+1])
                t++;

            R[i] = t;
            int k = 1;
            while(k <= t && R[i - k] != R[i] - k)
            {
                R[i + k] = min(R[i-k],(R[i]-k));
                k++;
            }
            t-=k;
            t=max(0,t);
            i+=k;
        }
        int good[s.size()];
        for(int zz=0;zz<s.size();zz++)
            good[zz]=0;

        good[0]=1;

        for(int zz=0;zz<s.size()-1;zz++)
        {
            if(R[zz]>0 && good[zz-R[zz]]==1)
            {
                good[zz+R[zz]]=1;
            }
        }
      /*  cout<<s.size()<<" ";
        for(int zx=0;zx<s.size();zx++)
        {
            cout<<zx<<" "<<good[zx]<<endl;
        }*/
        if(good[s.size()-2]==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
