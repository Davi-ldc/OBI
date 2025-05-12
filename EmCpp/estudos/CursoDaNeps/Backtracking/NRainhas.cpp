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

bool isVal(vector<vector<int>> M, int i, int j){

}

int main(){
    
    int N;
    cin >> N;


    vector<vector<int>> M(N, vector<int>(N)); 
    for (int i =0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> M[i][j];
        }
    }




    return 0;
}