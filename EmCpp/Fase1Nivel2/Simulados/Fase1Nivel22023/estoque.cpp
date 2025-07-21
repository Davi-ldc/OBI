//https://neps.academy/br/exercise/2319
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int N, M;
    cin >> N >> M;

    //matrix NxM
    vector<vector<int>> Tabela(N, vector<int>(M));

    for(int i =0; i<N; i++) {
        for(int j=0; j<M; j++){
            cin >> Tabela[i][j];
        }
    }

    int A;
    cin >> A;

    int resposta = 0;
    for (int i =0; i<A; i++){
        int v1, v2;
        cin >> v1 >> v2;

        if(Tabela[v1-1][v2-1]>0){
            Tabela[v1-1][v2-1] -= 1;
            resposta++;
        };
    }

    cout << resposta;

    return 0;
}