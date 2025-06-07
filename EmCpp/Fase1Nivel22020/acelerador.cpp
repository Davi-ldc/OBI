#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
6, 6+8, 6+8*2, 6+8*3 -> 
7, 7+8, 7+8*2, 7+8*3 -> 
8, 8+8, 8+8*2, 8+8*3 -> 
*/

//Se o numero - 6 for multiplo de 8 -> é o primeiro
//Se o numero - 7 for multiplo de 8 -> é o segundo
//Se o numero - 8 for multiplo de 8 -> é o terceiro


/*

if (condição){
    executa esse codigo aqui
}
A += 1;
A = A + 1;

while (condição){
    executa o codigo
}
*/

int main(){

    int N; 
    cin >> N;

    int resposta =0;

    //opção burra
    // while (N>8){
    //     N -= 8;
    // }


    if (N<=8){
        if(N==6){
            resposta = 1;
        }
        if(N==7){
            resposta = 2;
        }
        if(N==8){
            resposta = 3;
        }
    }
    else{
        if( (N-6)%8 == 0 ){
            resposta = 1;
        }
        if( (N-7)%8 == 0 ){
            resposta = 2;
        }
        if( (N-8)%8 == 0 ){
            resposta = 3;
        }
    }

    cout << resposta;

    return 0;
}