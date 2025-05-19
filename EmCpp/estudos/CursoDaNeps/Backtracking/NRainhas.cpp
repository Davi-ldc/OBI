//https://neps.academy/br/course/estrategias-avancadas-de-programacao/lesson/n-rainhas

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
É relativamente simples, só pensar na arvore de possibilidades, se o tabuleiro é NxN então pra cada linha
tem que ter uma rainha, tipo o inicial da arvore é na primeira coluna a rainha posicionada de 0 a N.
A partir dai agente vai andando pela arvore onde cada posição gera mais N mas corta as ramificações invalidas.

Toda vez que chegarmos no final (i == M.size()), ou seja, posicionarmos N rainhas, contamos mais uma possibilidade
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
        //cima direita 
        if(i+k < M.size() && j+k < M.size()){
            if(M[i+k][j+k] == 1) return false;
        }
        //baixo esquerda
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

int Nsolucoes(vector<vector<int>>& M, int i){

    //se chegou na ultima linha
    if(i == M.size()){
        return 1;
    }

    int resposta = 0;

    //pra cada j vai testando  uma possibilidade 
    for(int j = 0; j < M.size(); j++){
        if(isVal(M, i, j)){
            M[i][j] = 1;
            resposta += Nsolucoes(M, i+1);
            M[i][j] = 0;
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
        vector<vector<int>> M(sizes[i], vector<int>(sizes[i],0));
        int resposta = Nsolucoes(M, 0);
        cout << resposta << endl;
    }

    return 0;
}