//https://neps.academy/br/course/estrategias-avancadas-de-programacao/lesson/n-rainhas

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
O problema é posicionar N rainhas em um tabuleiro NxN. Ou seja, pra cada coluna tem N possibilidades de onde posicionar
uma rainha, e na proxima tmb. Da pra resolver na mesma logica do soduko, tenta botar uma rainha, se for valido
passa pra proxima, se não retorna 

Mas nesse caso, ele quer o numero de soluções. 
*/

//testa se é valido posicionar uma rainha em i, j
bool isVal(vector<vector<int>>& M, int i, int j){
    
    //linha
    for(int k = 0; k < M.size(); k++){
        if(M[i][k] == 1) return false;
    }

    //coluna
    for(int k = 0; k < M.size(); k++){
        if(M[k][j] == 1) return false;
    }

    //diagonal
    for(int k = 0; k < M.size(); k++){
        //cima
        if(i+k < M.size() && j+k < M.size()){
            if(M[i+k][j+k] == 1) return false;
        }
        //baixo
        if(i-k >= 0 && j-k >= 0){
            if(M[i-k][j-k] == 1) return false;
        }
        //cima esquerda
        if(i+k < M.size() && j-k >= 0){
            if(M[i+k][j-k] == 1) return false;
        }
        //cima direita
        if(i-k >= 0 && j+k < M.size()){
            if(M[i-k][j+k] == 1) return false;
        }
    }

    return true;
}

int Nsolucoes(vector<vector<int>>& M, int i, int j){

    //se chegou na ultima linha
    if(i == M.size()){
        return 1;
    }

    int resposta = 0;

    for(int k = 0; k < M.size(); k++){
        if(isVal(M, i, k)){
            M[i][k] = 1;
            resposta += Nsolucoes(M, i+1, k);
            M[i][k] = 0;
        }
    }

    return resposta;

}

int main(){
    
    int N;
    cin >> N;


    //tabuleiro
    vector<int> sizes(N);
    for (int i = 0; i < N; i++){
        cin >> sizes[i];
    }

    for (int i =0; i<N; i++){
        vector<vector<int>> M(N, vector<int>(sizes[i],0));
        cout << Nsolucoes(M, 0, 0) << endl;
    }

    return 0;
}