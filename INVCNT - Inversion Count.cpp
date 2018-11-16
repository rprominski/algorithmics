#include<iostream>
#include<vector>
using namespace std;
long long int licznik=0;
//vector<int> vec;
vector<int> mergeSort(int poczatek,int koniec,vector<int> &vec)
{
    if(poczatek==koniec)
        return vector<int>{vec[poczatek]};


    int sr=(poczatek+koniec)/2;
    vector<int> tab1=mergeSort(poczatek,sr,vec);
    vector<int> tab2=mergeSort(sr+1,koniec,vec);
    vector<int> tab3;
    tab3.resize(tab1.size()+tab2.size());
    int i=0,j=0,q=0,s1,s2;
    s1=tab1.size();
    s2=tab2.size();
    while(i<s1 || j<s2)
    {
       // cout<<poczatek<<" "<<koniec<<endl;
        if(i==s1)
        {
            while(j<s2)
            {
                tab3[q]=(tab2[j]); q++;
                j++;
            }
            break;
        }
        if(j==s2)
        {
            while(i<s1)
            {
                tab3[q]=(tab1[i]); q++;
                i++;
            }
            break;
        }
        if(tab1[i]<=tab2[j])
        {
            tab3[q]=(tab1[i]); q++;
            i++;
        }
        if(tab1[i]>tab2[j])
        {
            tab3[q]=(tab2[j]); q++;
            j++;
            licznik+=(s1-i);
        }
    }
    return tab3;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++)
    {

        cin>>n;
        int a;
            vector<int> vec(n);
        licznik=0;
        for(int j=0;j<n;j++)
        {
            cin>>a;
            vec[j]=a;

        }
        vector<int> taba=mergeSort(0,n-1,vec);
        cout<<licznik<<endl;
    }



    return 0;
}
