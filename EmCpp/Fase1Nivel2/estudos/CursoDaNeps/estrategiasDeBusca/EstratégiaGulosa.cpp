#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

int main(){

    int S;

    cin >> S;

    vector<int> M = {1,5,10,25,50,100};
    sort(M.begin(),M.end(), [](int a, int b){return a>b;} );

    int resposta = 0;
    for (int i =0; i<M.size(); i++){
        while(S >= M[i]){
            S -= M[i];
            resposta++;
        }
    }

    cout << resposta;

    return 0;
}