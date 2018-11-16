#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void justify(int x)
{
    if(x>0 && x<10)
        {
            cout<<"  "<<x<<" ";;
            return;
        }
    if( (x<0 && x>-10) || (x>=10))
       {
            cout<<" "<<x<<" ";
            return;
       }
    cout<<x<<" ";
}
void wyswietl(vector<pair<int,int> > x)
{
    for(int i=0;i<x.size();i++)
    {
        cout<<i<<" - "<<x[i].first<<" "<<x[i].second<<endl;
    }
}
void wyswietl2(vector<vector<int> > x)
{
    for(int i=0;i<x.size();i++)
    {
        for(int j=0;j<x[i].size();j++)
            cout<<x[i][j]<<" ";
        cout<<endl;
    }
}
class Graph
{
public:
    vector< vector<int> > matrix;
    vector< vector<int> > reverseMatrix;
    vector< pair<int,int> > successors;
    vector< pair<int,int> > predecessors;
    vector< pair<int,int> > notIncidents;
    int size;


    void setSize(int n)
    {
        n+=2;
        size=n;
        matrix.resize(n);
        for(int i=0;i<n;i++)
        {
                matrix[i].resize();
                matrix[i][0]=0;
                matrix[0][i]=0;


        }
    }
    Graph(int n)
    {
        setSize(n);
    }
    Graph();

    void insert(int v1, int v2)
    {

    }

    void display()
    {
        cout<<"  ";
        for(int i=1;i<size;i++)
            justify(i);
      //      cout<<i<<"  ";
        cout<<endl;

        for(int i=1;i<size;i++)
        {
            cout<<i<<" ";
          //  justify(i);
            for(int j=1;j<size;j++)
            {  // cout<<"#";
                justify(matrix[i][j]);
              //  cout<<"#";
             //   cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph graf(6);
   // wyswietl(graf.predecessors);
    graf.insert(1,3);
//    wyswietl(graf.reverseMatrix);
  //  cout<<graf.reverseMatrix[0].first;
    graf.insert(1,2);
    graf.insert(1,5);
    graf.insert(1,6);
    graf.insert(1,4);
  //  graf.insert(4,1);
    graf.insert(3,1);
   // graf.insert(2,3);
   // graf.insert(1,4);
    graf.insert(2,1);
  //  graf.insert(3,4);

  //  graf.insert(3,1);

  //  graf.insert(6,5);
  //  graf.insert(4,5);
//
    //graf.insert(3,4);
  //  graf.insert(3,1);
    graf.display();
    wyswietl(graf.notIncidents);

    return 0;
}
