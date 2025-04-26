// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class graph
{
    private:
    int mat[20][20];
    int n;
     public:
    void accept();
    void display();
    void prims_algorithm(int strver);
};
void graph::accept()
{
    int i,j;
    char ch;
    cout<<"enter the no of vertces in the graph"<<endl;
    cin>>n;
    cout<<"enter the elements in adjency matrix"<<endl;
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<"is there an path from "<<i<<" to "<<j<<" (y/n)??"<<endl;
            cout<<"enter choice"<<endl;
            cin>>ch;
            if(ch=='y')
            {
                cout<<"enter choice"<<endl;
            cin>>mat[i][j];
            }
            else
            mat[i][j]=9999;
        }
    }
}
void graph::display()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
void graph::prims_algorithm(int strver)
{
    int min,loc,cost=0,nearest[20];
    nearest[strver]=-1;
    for(int i=0;i<n;i++)
    {
        if(i!=strver)
        nearest[i]=strver;
    }
     for(int i=0;i<n-1;i++)
     {
           min=9999;    
         for(int j=0;j<n;j++)
         {
             if(nearest[j]!=-1 && mat[j][(nearest[j])]<min)
             {
                 min=mat[j][(nearest[j])];
                 loc=j;
             }
         }
            cost=cost+mat[loc][(nearest[loc])];
            nearest[loc]=-1;
             for(int k=0;k<n;k++)
             {
        if(nearest[k]!=-1 && mat[loc][k]<mat[k][(nearest[k])])
                 nearest[k]=loc;
             }
     }
       cout<<"cost is:"<<cost<<endl;
}
int main() 
{
  graph g1;
  g1.accept();
  cout<<"the entered adjency matrix is:"<<endl;
  g1.display();
  int strver;
  cout<<"enter the starting vertex"<<endl;
  cin>>strver;
  g1.prims_algorithm(strver);
    return 0;
}
