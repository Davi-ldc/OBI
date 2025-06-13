#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
Entrada:
4
4 2 5 3

quer dizer que 4 pessoas gostaram do brinquedo 1, 2 do brinquedo 2...
Logo a maior coluna tem altura 5
*/

int main(){

    int N;
    cin >> N;

    vector<int> lista(N);
    for (int i = 0; i < N; i++){
        cin >> lista[i];
    }
    int maior_valor = 0;
    for (int i = 0; i < N; i++){
        if (lista[i] > maior_valor) {
            maior_valor = lista[i];
        }
    }

    vector<vector<int>> M;

    for (int i = 0; i < N; i++){
        int altura = lista[i];
        vector<int> coluna(altura, 1);//preenche com 1
        while (coluna.size() < maior_valor) {
            coluna.push_back(0);//o resto vai ser 0
        }
        M.push_back(coluna);
    }

    for (int i = M[0].size() - 1; i >= 0; i--) { 
        for (int j = 0; j < N; j++) {
            cout << M[j][i] << " "; 
        }
        cout << endl;
    }

    return 0;
}