#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Cada linha deve conter todos os números de 1 a 9, sem repetição.
// Cada coluna deve conter todos os números de 1 a 9, sem repetição.
// Cada subgrade 3x3 deve conter todos os números de 1 a 9, sem repetição.

/*
Vamosss lá, a ideia aqui é 

*/




int main(){

    vector<vector<int>> tabuleiro;

    for (int i =0; i<9; i++){// pra cada linha
        for (int j = 0; j<9; j++){// le 9 numeros
            int temp;
            cin >> temp;
            tabuleiro[i].push_back(temp);
       }
    }

    //debug
    // for (auto x : tabuleiro){
    //     for (int i : x){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }


    return 0;
}