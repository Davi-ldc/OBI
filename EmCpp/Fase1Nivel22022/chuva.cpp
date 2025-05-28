#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

    int N, Sd; cin >> N >> Sd;
    vector<int> V(N);

    for(int i = 0; i<N; i++){
        cin >> V[i];
    }

    int resposta = 0;

    //soma todas as possibilidades de subarrays que tenham soma igual a Sd
    for(int i = 0; i<N; i++){
        int soma = 0;
        for(int j = 0; j<N-i; j++){
            soma += V[j+i];
            if(soma == Sd){
                resposta++;
            }
        }
    }

    cout << resposta;
    return 0;
}
