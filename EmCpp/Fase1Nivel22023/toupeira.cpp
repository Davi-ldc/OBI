#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int S, T;//número de salões, número de tuneis
    cin >> S >> T;

    vector<vector<int>> M(S, vector<int>(S,0));

    for (int i =0; i<T; i++){
        int a, b;
        cin >> a >> b;
        M[b-1][a-1] = 1;
    }

    //debug
    // for(int i = 0; i<S; i++){
    //     for (int j=0;j<S;j++){
    //         cout << M[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int P; cin >> P;

    int resposta =0;
    for (int i =0; i<P;i++){
        int size; cin >> size;
        vector<int> passeio(size,0);

        //preenche o vetor
        for(int j=0;j<size;j++){cin>>passeio[j];}

        bool valido = true;
        for (int k=0; k<size-1; k ++){
            if(M[passeio[k]-1][passeio[k+1]-1] != 1 && M[passeio[k+1]-1][passeio[k]-1] != 1 ){
                valido = false;
                break;
            }
        }
        if(valido){resposta++;}
    }

    cout << resposta;

    return 0;
}