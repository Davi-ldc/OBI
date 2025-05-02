//https://neps.academy/br/course/fundamentos-das-estruturas-de-dados/lesson/copa-do-mundo

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    //matrix 15x2 tem 15 duplas 
    //fica assim [ [4,1],[1,0] ]
    vector<vector<int>> placar(15, vector<int>(2));
    string letras = "ABCDEFGHIJKLMNOP";

    for (int i=0; i<15; i++){
        for(int j=0; j<2; j++){
            cin >> placar[i][j];
        }
    }

    //oitavas de final
    for (int i=0; i<8; i++){
        if (placar[i][0] > placar[i][1]){
            letras.erase(letras.begin()+1+i);
        }
        else {
            letras.erase(letras.begin()+i);//remove o primeiro
        }
    }

    //quartas de final
    for (int i=8; i<12; i++){
        if (placar[i][0] > placar[i][1]){
            letras.erase(letras.begin()+1+i-8);
        }
        else {
            letras.erase(letras.begin()+i-8);//remove o primeiro
        }
    }

    //semiFinal 
    for (int i=12; i<14; i++){
        if (placar[i][0] > placar[i][1]){
            letras.erase(letras.begin()+1+i-12);
        }
        else {
            letras.erase(letras.begin()+i-12);//remove o primeiro
        }
    }

    //final 
    for (int i=14; i<15; i++){
        if (placar[i][0] > placar[i][1]){
            letras.erase(letras.begin()+1+i-14);
        }
        else {
            letras.erase(letras.begin()+i-14);//remove o primeiro
        }
    }

    cout << letras << endl;

    //debug
    // for (auto letra : letras){
    //     cout << letra;
    // }

    // for (auto dupla : placar){
    //     for (auto valor : dupla){
    //         cout << valor;
    //     }
    //     cout << endl;
    // }

}