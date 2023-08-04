#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topo_Khan(int n, int &v, int order[], int* aux, vector<int>* Adj){
    priority_queue <int, vector<int>, greater<int> > prioridades;
    v = 0;
    int u;
    for(int i=1; i<=n; i++)
        if (!aux[i]) 
            prioridades.push(i);
                
        //Khan        
    while(!prioridades.empty()){
        u = prioridades.top();
        prioridades.pop();
        for(int i=0; i<Adj[u].size(); i++){
            aux[Adj[u][i]]--;
            if (!aux[Adj[u][i]])
                prioridades.push(Adj[u][i]);
        }
        order[v++] = u;
    }
}

int main(){
    int n,m;
    int x, y;
    int vertex;

    int order[10002];
    int aux[10002];    
    vector <int> AdjMatrix[10002]; 
        
    cin >> n >> m;
    for (int i=0; i<m; i++){
        cin >> x >> y;
        aux[y]++;
        AdjMatrix[x].push_back(y);
    }
        
    topo_Khan(n, vertex, order, aux, AdjMatrix);      

    if (vertex == n)
        for(int i=0; i<n; i++)
            cout << order[i] << " ";  
    else 
        cout << "Sandro fails." << "\n";        

    return 0;
}
