#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Cada linha deve conter todos os números de 1 a 9, sem repetição.
// Cada coluna deve conter todos os números de 1 a 9, sem repetição.
// Cada subgrade 3x3 deve conter todos os números de 1 a 9, sem repetição.

/*
Vamosss lá, Vamos pensar do jeito burro primeiro. Imagina que agnt tem 17 numeros já prenchidos
e quer achar o proximo, como humano mesmo, poderiamos só ir testando e ver se o numero é valido

Mas pera, quando que ele é valido? Dado o indice i,j um número é valido se na linha não tiver nenhum numero
igual a ele ou seja pra cada elemento em M[i] nenhum pode ser igual ao numero desejado. Da até pra cmc com o set
{1,2,3,4,5,6,7,8,9} e ir iterando sobre M[i][X] tirando os valores k do set (o (log N)) E o mesmo para M[X][j]

Ta, mais ainda falta chechar o quadrante. Pensa neles como uma matriz:
M -> 
{
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
}
repara que é so pegar a posição i/3 e j/3 nessa matrix pra achar o quadrante

tipo: (é o mesmo na vertical)
0 0 0 1 1 1 2 2 2 index
0 1 2 3 4 5 6 7 8 posição; Ta já sabemos checar se um numero é valido.

Pra cada iteração eu poderia pegar meu set com os numeros possiveis, e ver ir deletando os que aparecem
na linha; na coluna; no quadrante. e se não tiver nenhum faz o backtrack 


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