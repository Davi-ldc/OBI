//https://neps.academy/br/course/estrategias-avancadas-de-programacao/lesson/o-problema-da-mochila

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
A ideia aqui é, você sabe que tem N itens, cada um com um peso e um valor, e uma mochila com capacidade C.
e quer saber o valor maximo que pode carregar. Para resolver o problmema criamos uma matrix M
onde M[i][j] representa o valor máximo que pode ser obtido com os primeiros i itens e capacidade j da mochila.


*/

int main(){

    int N, C; cin >> N >> C; //N itens, C capacidade da mochila
    vector<int> peso(N), valor(N);
    for(int i = 0; i < N; i++){
        cin >> peso[i] >> valor[i];
    }

    //matrix de memorização
    vector<vector<int>> M(N + 1, vector<int>(C + 1, 0));
    // Preenchendo a matriz
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= C; j++){
            //Se o peso do item atual é maior que a capacidade j, não podemos incluí-lo
            if(peso[i - 1] > j){
                M[i][j] = M[i - 1][j]; 
            } else {
                M[i][j] = max(M[i - 1][j], M[i - 1][j - peso[i - 1]] + valor[i - 1]);
            }
        }
    }

    cout << M[N][C] << endl;

    return 0;
}