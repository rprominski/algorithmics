#include<iostream>
#include<vector>
using namespace std;

int rozmiar;
int tab[100009][10];
int wynik[1100009];

void generujWynik(int x)
{
	while(1)
	{
		int j;
		bool q=0;
		for(int i=0;i<10;i++)
		{
			j=tab[x][i];
			if (j>=0)
            {
                q=1;
                tab[x][i]=-1;
                break;
            }
		}
		if (q==false)
            break;

		generujWynik(j);
	}
	wynik[rozmiar]=x%10;
	rozmiar++;
}
int main()
{
    ios_base::sync_with_stdio(0);
	int n;
	while(cin>>n)
	{
		if (n==0)
			break;
		if (n==1)
		{
			cout<<"0123456789"<<endl;
			continue;
		}
		else
        {
            rozmiar=0;
            int m=1;
            for (int i=1; i<n; i++)
                m*=10;
            for (int j=0; j<m; j++)
                for (int k=0; k<10; k++)
                    tab[j][k]=10*(j%(m/10))+k;

            generujWynik(0);

            for (int i=0; i<n-2; i++)
                cout<<0;
            for (int i=rozmiar-1; i>=0; i--)
                cout<<wynik[i];
            cout<<endl;
        }
	}
	return 0;
}
