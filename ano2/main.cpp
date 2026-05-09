#include <iostream>
#include <vector>
#include <set>
#define int long long

using namespace std;

signed main (){
    
    int M,N; cin >> M >> N;

    vector<vector<int>> G(M, vector<int>(N));
    
    for (int i =0; i<M; i++){
        for (int j=0;j<N;j++){
            char c; cin >> c;
            if (c=='#') G[i][j] = 0;
            else if (c=='.') G[i][j] = 1;
        }
    }

    int steps = 0;
    int index = 0;
    vector<pair<int,pair<int,int>>> pos;

    pair<int,pair<int,int>> inicial = {0,{0,0}};
    pos.push_back({inicial});
    
    set<pair<int,int>> visited;
    visited.insert({0,0});

    int b = 0;
    while (true){
        //vai começar olhando 0,0
        int i = pos[index].first; int j = pos[index].second.first;
        if (i==M-1 && j==N-1) {cout << pos[index].second.second; break;}//se chegou no final para

        //ai checa todos os lados e adiciona na fila
        //direita menor que N por que se N é 4 vai 0,1,2,3
        if(j+1 < N && G[i][j+1] == 1 && visited.find({i,j+1}) == visited.end()) {pos.push_back({i,{j+1,pos[index].second.second+1}});visited.insert({i,j+1});}
    
        //esquerda
        if(j-1 >= 0 && G[i][j-1] == 1 && visited.find({i,j-1}) == visited.end()) {pos.push_back({i,{j-1,pos[index].second.second+1}});visited.insert({i,j-1});}
    
        //cima
        if(i+1 < M && G[i+1][j] == 1 && visited.find({i+1,j}) == visited.end()) {pos.push_back({i+1,{j,pos[index].second.second+1}});visited.insert({i+1,j});}
    
        //baixo
        if(i-1 >= 0 && G[i-1][j] == 1 && visited.find({i-1,j}) == visited.end()) {pos.push_back({i-1,{j,pos[index].second.second+1}});visited.insert({i-1,j});}
        
        if (b == 1 && index == pos.size()-1){cout << "sem caminho"; break;}
        b=1;
        index++; //vai drenando a fila de baixo pra cima
    }

    return 0;
}