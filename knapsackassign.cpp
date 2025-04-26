#include<iostream>
using namespace std;
class knapsack
{
int w,n;
int wt[20],p[20];
int b[20][20];
public:
void accept_data();
void display_data();
void dynamicprog();
void backtrack();
};
void knapsack::accept_data()
{
cout<<"enter the no of object"<<endl;
 cin>>n;
 cout<<"enter the knapsack size"<<endl;
 cin>>w;
 for(int i=1;i<=n;i++)
 {
 cout<<"enter the wt and profit of "<<i<<endl;
     cin>>wt[i];
     cin>>p[i];
 }
}
void knapsack::display_data()
{
cout<<"knapsack size is"<<w<<endl;
cout<<"wieght "<<", "<<"profit"<<endl;
for(int i=1;i<=n;i++)
 {
     cout<<wt[i]<<","<<p[i]<<" "<<endl;
 }
}
void knapsack::dynamicprog()
{
    for(int i=0;i<=w;i++)
    {
       b[0][i]=0;
    }
      for(int w1=1;w1<=n;w1++)
      {
         b[w1][0]=0;
      }
       for(int i=1;i<=n;i++)
       {
          for(int w1=0;w1<=w;w1++)
          {
               if(wt[i]<=w1)
               {
                 if((p[i]+b[i-1][(w1-wt[i])])>b[i-1][w1])
                 b[i][w1]=p[i]+b[i-1][(w1-wt[i])];
                 else
                 b[i][w1]=b[i-1][w1];
                }
                  else
                  b[i][w1]=b[i-1][w1];
            }
          }  
             for(int w2=0;w2<=n;w2++)
            {
              for(int i=0;i<=w;i++)
              {
                  cout<<b[w2][i]<<" ";
               }
                  cout<<endl;
                  
            } 
              cout<<"maximum profit is:"<<b[n][w]<<endl;
}
void knapsack::backtrack()
{
    int i,k;
     i=n;
     k=w;
     while(i>0 && k>0)
     {
         if(b[i][k]!=b[i-1][k])
         {
         cout<<"element selected:"<<i<<endl;
              k=k-wt[i];
              i=i-1;
         }
         else
         {
              i=i-1;
         }
     }
}
int main()
{
knapsack ks;
ks.accept_data();
ks.display_data();
ks.dynamicprog();
ks.backtrack();
return 0;
}

