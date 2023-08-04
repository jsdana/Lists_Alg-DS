#include <iostream>
using namespace std;

#define infinito 2147483647

int minimumCost(int N, int K, int* heights){
    int cost[N];
    for(int i=0; i<N; i++)
        cost[i] = infinito;

    cost[0] = 0;
    for(int i=0; i<N; i++){
        for(int j= i+1; j<= i + K; j++){
            if(j<N)
                cost[j] = min(cost[j], cost[i] + abs(heights[j] - heights[i]));
        }
    }

    return cost[N-1];
}

int main(){

    int N, K;

    cin >> N >> K;
    int heights[N];
    for(int i=0; i<N; i++)
        cin >> heights[i];

    cout << minimumCost(N, K, heights);
    

    return 0;
}
