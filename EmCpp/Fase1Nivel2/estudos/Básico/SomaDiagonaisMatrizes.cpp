//https://neps.academy/br/exercise/201

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int B[3][3];

    for (int i = 0; i<3; i++){
        for (int c = 0; c<3; c++){
            cin >> B[c][i];
        }
    }

    int somaP = 0;
    int somaS = 0;
    for (int i = 0; i<3; i++){
        somaP += B[i][i];
        somaS += B[i][2-i];
    }
    cout << "Diagonal principal: " << somaP << endl;
    cout << "Diagonal secundaria: " << somaS;

    return 0;
}