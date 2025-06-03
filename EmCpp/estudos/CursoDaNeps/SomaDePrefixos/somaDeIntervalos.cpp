#include <iostream>
#include <bits/stdc++.h>

using namespace std; 

/*
esse é um classico pra entender prefix sum, a gente tem um array aleatório tipo:
1 2 3 4 5 e quer saber qual a soma entre o intervalo [L,R]. Pra isso criamos uma prefixSum igual a 
0 1 3 6 10 15 tal que  Pf[i] = V[1]+V[2]...+ V[i]. 

Repara que se quisermos o intervalo 1, 3 basta fazer Pfsum[3+1]-Pfsum[1]

*/

int main(){

    int N, Q; cin >> N >> Q;

    vector<int> V(N);

    for(int i=0; i<N; i++){
        cin >> V[i];
    }

    vector<long long> PfSum(N+1);
    PfSum[0] = 0LL;
    long long soma = 0LL;
    for(int i=0; i<N; i++){
        soma += V[i];
        PfSum[i+1] = soma;
    }

    vector<pair<int,int>> Consultas;
    for(int i=0; i<Q; i++){
        int a, b; cin >> a >> b;
        Consultas.push_back({a,b});
    }

    //debug
    // for(int x : PfSum){
    //     cout << x << " ";
    // }
    // cout << endl;

    for(auto x : Consultas){
        cout << PfSum[x.second+1] - PfSum[x.first] << endl;
    }

    return 0;
}
