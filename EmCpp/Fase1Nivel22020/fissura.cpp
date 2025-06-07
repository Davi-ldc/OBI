#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*

4
450
150
50
100
37
*/

int main(){

    int NContas;
    cin>> NContas;//quantas contas eu tenho pra pagar 

    int dinheiro; 
    cin >> dinheiro;//quanto dinheiro eu tenho

    vector<int> = ValorDasContas; //{150,50,100,37}

    // // para i =0. enquanto i<N; i++
    for (int i=0; i<NContas; i++){
        int variavelQualQuer;
        cin >> variavelQualQuer;

        ValorDasContas.push_back(variavelQualQuer);
    }

    sort(ValorDasContas.begin(), ValorDasContas.end());//descrescente

    int resposta = 0;
    int i = 0;
    while (dinheiro > ValorDasContas[i] && i < ValorDasContas.size()-1 ){
        resposta +=1;
        dinheiro -= ValorDasContas[i];
        i+=1;
    }

    /*
    3
    100
    80
    60
    50

    50 - 60 - 80 
    */

    cout << resposta; 
    return 0;
}