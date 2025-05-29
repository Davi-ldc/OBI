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

    vector<int> prefixSum(N);
    int soma = 0;
    for(int i =0; i < N; i++){
        soma += V[i]
        prefixSum[i] = soma; 
    }

    //repara que a soma de a até b é prefix[b] - prefix[a]

    //ai ele quer saber de quantas formas podemos somar R

    cout << resposta;
    return 0;
}
