//https://neps.academy/br/exercise/2711

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    //maior nota C que faz K candidatos serem aprovados
    //N é o numero de pessoas. N > K
    //K é o numero minimo de pessoas aprovadas
    int N,K;
    cin >> N >> K;
    vector<int> V;

    for (int i =0; i<N; i++){
        int temp;
        cin >> temp;
        V.push_back(temp);
    }

    sort(V.begin(),V.end());

    //na pratica ele meio que quer o indice, tipo 
    //se agente tem N pessoas com notas em ordem crescente
    //pra K serem aprovados a nota de corte deve ser
    //size -K

    cout << V[(V.size())-K];



    return 0;
}