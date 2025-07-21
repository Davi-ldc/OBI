#include <iostream> 
#include <bits/stdc++.h>

using namespace std;

/*
Ta, agente sabe quer saber quantas possibilidades de K elementos positivos somam R
Repara que não da pra repetir elementos. então o ideial é trabalhar em ordem crescente

já que ABC BCA ACB... são iguais.

O pulo do gato é perceber que da pra evitar muitas checagens definindo o maior e o menor numero
que pode ser adicionado na lista de K elementos.

*/

int sum(vector<int>& V){
    int t = 0;
    for (int x : V){
        t+=x;
    }
    return t;
}

int possibilidades(int& SomaDesejada, int& K, vector<int>& V){
    int SomaAtual = sum(V);

    // cout << endl;
    // cout << "{";
    // for ( int c : V){
    //     cout << c << " ";
    // }
    // cout << "}";

    //caso base
    if (V.size()==K){//se o tamanho for igual a K
        if(SomaAtual==SomaDesejada){//se a soma for igual a R
            // cout << "MAIS UM";
            return 1;
        }
        return 0; //se n retorna 0
    }

    //Ai pra cada posição no vetor de K elementos a gnt intera
    int resposta=0;
    int anterior = V.empty() ? 0 : V[V.size()-1];

    //sem repetir nenhum elemento
    int menorPossivel = anterior + 1;

    int maiorPossivel = SomaDesejada - SomaAtual;

    for (int i = menorPossivel; i <= maiorPossivel; i++){
        V.push_back(i);
        resposta += possibilidades(SomaDesejada, K, V);
        V.pop_back();
    }

    return resposta;
}

int main(){

    int R, K;

    cin >> R >> K; 

    vector<int> V;

    cout << possibilidades(R, K, V);

    return 0;
}
