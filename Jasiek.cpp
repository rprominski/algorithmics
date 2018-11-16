#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double pole(vector<pair<double,double> > &punkty)
{
    double wyn=0;
//    punkty[punkty.size()]=punkty[0];
  //  cout<<punkty[0].first<<" "<<punkty[0].second<<endl;
  punkty.push_back(punkty[0]);
    for(double i=0;i<punkty.size()-1;i++)
    {
        cout<<punkty[i].first<<" "<<punkty[i+1].second<<" "<<punkty[i+1].first<<" "<<punkty[i].second<<endl;
        wyn+=punkty[i].first*punkty[i+1].second-punkty[i+1].first*punkty[i].second;
    }

    return wyn;
}
int main()
{
    char z,q;
    while(cin>>q)
    {
        if(q=='P')
        {
            vector<char> tab;

            while(cin>>z)
            {
                if(z=='K')
                    break;

                tab.push_back(z);
            }
            if(tab.size()==0)
            {
                cout<<1<<endl;
                continue;
            }
            char poprz=tab[tab.size()-1];
            double x=1,y=1;
            vector<pair<double,double> > punkty;
            for(double i=0;i<tab.size();i++)
            {
                if(poprz=='N')
                {
                    if(tab[i]=='N')
                    {
                        y+=2;
                    }
                    if(tab[i]=='S')
                    {
                        punkty.push_back(make_pair(x+1,y+1));
                        punkty.push_back(make_pair(x-1,y+1));
                        y-=2;
                    }
                    if(tab[i]=='E')
                    {
                        punkty.push_back(make_pair(x+1,y-1));
                        x+=2;
                    }
                    if(tab[i]=='W')
                    {
                        punkty.push_back(make_pair(x+1,y+1));
                        x-=2;
                    }
                }

                if(poprz=='S')
                {
                    if(tab[i]=='N')
                    {
                        punkty.push_back(make_pair(x-1,y-1));
                        punkty.push_back(make_pair(x+1,y-1));
                        y+=2;
                    }
                    if(tab[i]=='S')
                    {
                        y-=2;
                    }
                    if(tab[i]=='E')
                    {
                        punkty.push_back(make_pair(x-1,y-1));
                        x+=2;
                    }
                    if(tab[i]=='W')
                    {
                        punkty.push_back(make_pair(x-1,y+1));
                        x-=2;
                    }
                }
                if(poprz=='E')
                {
                    if(tab[i]=='N')
                    {
                        punkty.push_back(make_pair(x+1,y-1));
                        y+=2;
                    }
                    if(tab[i]=='S')
                    {
                        punkty.push_back(make_pair(x-1,y-1));
                        y-=2;
                    }
                    if(tab[i]=='E')
                    {
                        x+=2;
                    }
                    if(tab[i]=='W')
                    {
                        punkty.push_back(make_pair(x+1,y-1));
                        punkty.push_back(make_pair(x+1,y+1));
                        x-=2;
                    }
                }
                if(poprz=='W')
                {
                    if(tab[i]=='N')
                    {
                        punkty.push_back(make_pair(x+1,y+1));
                        y+=2;
                    }
                    if(tab[i]=='S')
                    {
                        punkty.push_back(make_pair(x-1,y+1));
                        y-=2;
                    }
                    if(tab[i]=='E')
                    {
                        punkty.push_back(make_pair(x-1,y+1));
                        punkty.push_back(make_pair(x-1,y-1));
                        x+=2;
                    }
                    if(tab[i]=='W')
                    {
                        x-=2;
                    }
                }
                poprz=tab[i];
            }
            cout<<pole(punkty)/8<<endl;;

        }
    }



    return 0;
}
