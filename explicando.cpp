#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
S = [1][1]
s = [1][2]
s = [2][1]
s = [2][2]

*/
int main() {

    vector<vector<int>> M;

    for (int i = 0; i<3; i++){
        vector<int> lista;
        for (int j =0; j<3; j++){
            int temp;
            cin>> temp;
            lista.push_back(temp);
        }
        M.push_back(lista);
    }

    //imprime a matriz
    for (int i = 0; i<3; i++){
        for (int j =0; j<3; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

/*


*/