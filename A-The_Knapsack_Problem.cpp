#include <iostream>
using namespace std;

long long Knapsack(int i, int j, int* w, int *v, long long** F){
    long long value;
    if(F[i][j] < 0){
        if(j<w[i])
            value = Knapsack(i-1, j, w, v, F);
        else
            value = max(Knapsack(i-1, j, w, v, F), v[i] + Knapsack(i-1, j - w[i], w, v, F));
        F[i][j] = value;
    }
    return F[i][j];
}

int main(){

    int S, N;
    int weight, value;

    cin >> S >> N;

    long long** F;
    F = new long long*[N+1];
    for(int i=0; i<=N; i++){
        F[i] = new long long[S+1];
        for(int j=0; j<=S; j++){
            if(i==0 || j==0)
                F[i][j] = 0;
            else
                F[i][j] = -1;
        }
    }
    
    int w[N+1]; int v[N+1];
    for(int i=1; i<=N; i++){
        cin >> weight >> value;
        w[i] = weight; v[i] = value;
    }

    cout << Knapsack(N, S, w, v, F);
}
