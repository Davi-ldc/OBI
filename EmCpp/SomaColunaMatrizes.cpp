//https://neps.academy/br/exercise/200

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

    for (int i = 0; i<3; i++){
        int soma = 0;
        for (int num : B[i]){ //literalmente o for num in list do python
            soma += num;
        }

        cout << "Coluna " << i <<": " << soma << endl;
        
    }
    

    return 0;
}