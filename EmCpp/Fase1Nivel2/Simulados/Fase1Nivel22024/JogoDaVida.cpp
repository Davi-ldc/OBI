//https://neps.academy/br/exercise/2714
//nem teve sacada nenhuma, como a entrada é muito baixa fiz em C N² msm e deu certo:)

#include <iostream> 
#include <bits/stdc++.h>

using namespace std;

int vizinhos(vector<vector<int>> M, int i, int j){

    int resposta =0;

    //Agente tem que checar 6 indices
    //M[i][j+1]; M[i][j-1] os do lado
    //M[i+1][j]; M[i+1][j-1] M[i+1][j+1] de baixo
    //M[i-1][j]; M[i-1][j-1] M[i-1][j+1] de cima

    if(j+1 < M.size()){
        resposta += M[i][j+1];
    }
    if (j-1 >= 0){
        resposta += M[i][j-1];
    }
    if (i+1 < M.size()){
        if(j+1 < M.size()){
            resposta += M[i+1][j+1];
        }
        if (j-1 >= 0){
            resposta += M[i+1][j-1];
        }
        resposta += M[i+1][j];
    }
    if (i-1 >= 0){
        if(j+1 < M.size()){
            resposta += M[i-1][j+1];
        }
        if (j-1 >= 0){
            resposta += M[i-1][j-1];
        }
        resposta += M[i-1][j];
    }

    return resposta;
}

int main(){

    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> M(N, vector<int>()); //matrix NxN

    for (int i=0; i<N; i++){
        string linha;
        cin >> linha;

        for (char c : linha){
            M[i].push_back(c - '0');
        }
    }

    
    for (int a =0; a<Q; a++){
        vector<vector<int>> M2 = M;//pra não alterar os vizinhos antes de checar tudo
        for (int i =0; i<N; i++) {
            for (int j=0; j<N; j++){
                int v = vizinhos(M, i, j);
                if (v==3 && M[i][j] == 0){
                    M2[i][j] = 1;
                }
                if (v<2 && M[i][j] == 1){
                    M2[i][j] = 0;
                }
                if (v>3 && M[i][j] == 1){
                    M2[i][j] = 0;
                }
            }
        }
        M = M2;
    }

    // cout << endl;
    // cout << M.size() << " " << M[0].size();
    // cout << endl;

    for (int i =0; i<N; i++) {
        for (int j=0; j<N; j++){
            cout << M[i][j];
        }
        cout << endl;
    }

    return 0;
}