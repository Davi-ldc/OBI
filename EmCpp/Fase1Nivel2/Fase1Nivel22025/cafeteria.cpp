#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
Se A = 200, B = 210, C = 250, D = 30
então a lista fica [0, 30, 60, 90, 120, 150, 180, 210]
Ele deseja no minimo 200 e no maximo 210
*/

int main(){

    //Ele so prepara cafe multiplo de D
    //Eu sei o volume minimo A, o volume maximo B e o volume do copo C
    //quero saber se é possivel preparar o cafe preenchendo o copo com 
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    vector<int> multiplos;
    for (int i = 0; i*D <= C; i++){
        multiplos.push_back(i * D);
    }

    bool possivel = false;
    for (int x: multiplos){
        int resto = C - x; 
        if (resto >= A && resto <= B){
            possivel = true;
            break; 
        }
    }

    if (possivel){
        cout << "S";
    } else {
        cout << "N";
    }

    return 0;
}