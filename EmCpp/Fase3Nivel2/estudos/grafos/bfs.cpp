void bfs(int v){

    vector<int> vis(n+1, 0); 

    vector<int> dist(n+1, 0); 

    queue<int> fila; 
    fila.push(v) ; vis[v] = 1 ;
    // v pra todos 
    while(!fila.empty()){
        auto at = fila.front() ; fila.pop() ; 
        for(auto a : grafo[at]){
            if(!vis[a]){
                fila.push(a) ; vis[a] = 1 ;
                dist[a] = dist[at] + 1 ; 
            }
        }
    }

}