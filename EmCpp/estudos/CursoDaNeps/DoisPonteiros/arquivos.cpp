#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
Ele quer o numero minimo de pastas e cada pasta pode levar no maximo 2 numeros com peso maximo = X
Ou seja, quantos pares tem tal que a+b = x;
*/

int main(){

    int N, x; //x é o valor desejado
    cin >> N >> x;  
    int resposta = 0;

    vector<int> V(N);
    for (int i=0;i<N;i++){
        cin >> V[i];
    }
    //crescente
    sort(V.begin(), V.end());//ai a gente pode ir formando pares os maiores com os menores

    int i =0;
    int j = V.size()-1;//ultimo

    while(i<=j){

        //ultimo sozinho
        if (i == j) {
            resposta++;
            break;
        }
        
        //A gente procura alguma valor que ao somar com V[i] seja <= x
        else if (V[i] + V[j] <= x){
            resposta++;
            i++;
            j--;
        }
        //Se V[i] + V[j] forem maiores que x então V[j] tem que ficar sozinho
        else{
            resposta++;
            j--;
        }
    }

    cout << resposta; 
    return 0;
}