//https://neps.academy/br/exercise/2321

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int V;
    cin >> V;

    vector<int> C(3);

    for (int i=0; i <3; i++){
        cin >> C[i];
    }
    sort(C.begin(), C.end());

    int resposta = 0;
    int i = 0;
    //s.size() por que quando i for = 3 ele acessaria lixo
    while(C.size() > i && V >= C[i]){
        V-= C[i];
        i++;
        resposta++;
    }

    cout << resposta;

    return 0;
}