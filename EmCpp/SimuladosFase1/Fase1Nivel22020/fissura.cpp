#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
A ideia aqui é ter um vetor que armazena a posição dos pontos de lava que precisam ser processados
ai agente cria um for que roda vetor.size() vezes e pra cada interação processa um ponto checando seus vizinhos
se um ponto for inundado, adicionamos ele na lista para ser processado. Quando tivermos processado todos os elementos
da lista quer dizer que não tem mais nenhum ponto que será inundado e o problema está resolvido! :)
*/

int main(){
    int N, F;
    cin >> N >> F;
    
    vector<vector<int>> M(N, vector<int>(N));
    
    // Lê a matriz
    for(int i = 0; i < N; i++){
        string temp;
        cin >> temp;
        for(int j = 0; j < N; j++){
            M[i][j] = temp[j] - '0';
        }
    }
    
    // Posição inicial
    if(M[0][0] <= F){
        M[0][0] = -1;
    }
    
    vector<pair<int,int>> novos; 
    if(M[0][0] == -1) {
        novos.push_back({0,0});
    }
    
    for(int k = 0; k<novos.size(); k++) {
        int i = novos[k].first;
        int j = novos[k].second;

        // baixo
        if(i > 0 && M[i-1][j] <= F && M[i-1][j] != -1) {
            M[i-1][j] = -1;
            novos.push_back({i-1, j});
        }
        // cima
        if(i < N-1 && M[i+1][j] <= F && M[i+1][j] != -1) {
            M[i+1][j] = -1;
            novos.push_back({i+1, j});
        }
        // esquerda
        if(j > 0 && M[i][j-1] <= F && M[i][j-1] != -1) {
            M[i][j-1] = -1;
            novos.push_back({i, j-1});
        }
        // direita
        if(j < N-1 && M[i][j+1] <= F && M[i][j+1] != -1) {
            M[i][j+1] = -1;
            novos.push_back({i, j+1});
        }
    }
    
    // Imprime o resultado
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(M[i][j] == -1){
                cout << "*";
            } else {
                cout << M[i][j];
            }
        }
        cout << endl;
    }
    
    return 0;
}