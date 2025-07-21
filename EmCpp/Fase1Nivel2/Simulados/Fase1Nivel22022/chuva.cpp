#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
O problema é dado uma lista N, quantas sublistas R tem soma = Sd
se todos os numeros fossem positivos dava pra resolver com sliding window, 2 ponteiros parados no começo
J sempre avança e soma += [j] ai enquanto currentSum for > Sd e i<=j i++ soma -= V[i].
acho que da pra adaptar o algoritimo pra receber 0, ou usar prefix sum mas nesse caso
a implementaçaõ em O(N²/2) passou por causa do check:
if(soma > Sd){
        break;
} 
*/

int main(){

    int N, Sd; cin >> N >> Sd;
    vector<int> V(N);

    for(int i = 0; i<N; i++){
        cin >> V[i];
    }

    int resposta = 0;

    for(int i =0; i<N; i++){
        int soma = 0;
        for(int j=i; j<N; j++){
            soma += V[j];
            if (soma == Sd){
                resposta++;
            }
            if(soma > Sd){
                break;
            }
        }
    }

    // int soma = 0;
    // int i = 0;
    // int j = 0;
    // int resposta = 0;

    // //Se J chegou ao final, não  tem mais nenhuma soma que some
    // while (j<V.size()){
        
    //     soma += V[j];

    //     if(soma == Sd){cout << "i: " << i << " j: " << j << " Soma: " << soma << endl; resposta++;}
    //     while ( soma > Sd && i <= j){
    //         soma -= V[i];
    //         i++;
    //         if(soma == Sd){cout << "i: " << i << " j: " << j << " Soma: " << soma << endl; resposta++;}
    //     }

    //     j++;
    // }

    cout << resposta;
    return 0;
}
