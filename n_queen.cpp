#include<iostream>
#include<cstdlib>

using namespace std;

int X[100]={0};


bool place(int r, int c){
    for (int i = 1; i<=r-1;i++){
        if(X[i]==c || abs(X[i]-c)==abs(i-r)){
            return false;
        }
    }   
    return true;
}

void print(int N){
    for(int i = 1; i<=N;i++){
        cout<< X[i] << " ";
    }
    cout<<endl;
      for(int i = 1;i<=N;i++){
       for(int j = 1; j<=N ; j++){
           if(X[i] == j){
               cout<<i<<" ";
           }
           else{
               cout<< "-"<<" ";
           }
       }
       cout<<endl;
   }
   cout<<endl;
}

int N_queen(int r, int N){
    for(int c = 1; c<=N; c++){
        if(place(r,c)) {
            X[r]=c;
            if(r==N) {
                print(N);
            }
            {
                N_queen(r+1,N);
            }
        }
    }
    return 0;
}


int main(){
    int N;
    cout <<"enter the value of N: ";
    cin>> N;
   int k = N_queen(1,N);

}
