#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*


*/

int main(){

    //uma grama proteina -> 4 calorias
    // grama de carboidrato -> 4 calorias
    // grama de gordura -> 9 calorias

    int N, Limite;//qnt de refeiçõe e limite de cal
    cin >> N >> Limite; 

    int calorias = 0;
    for (int i =0; i<N; i++){
        int proteinas, carboidratos, gorduras;
        cin >> proteinas >> gorduras >> carboidratos; 
        calorias += (proteinas * 4) + (carboidratos * 4) + (gorduras * 9);
    }

    int resposta = Limite - calorias;
    if (resposta < 0) {
        cout << "0";
    } else {
        cout << resposta;
    }

    return 0;
}