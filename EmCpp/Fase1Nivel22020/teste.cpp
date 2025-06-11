#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

    int N; 
    cin >> N;
    
    bool Valido = true;
    if ( !(1<=N<=9) ){
        Valido = false;
    }

    vector<vector<int>> S = {
        {0,3,0, 6,4,5, 0,8,0},
        {0,0,1, 0,8,0, 2,0,0},
        {0,5,0, 6,0,0, 3,9,0},

        {1,0,0, 0,7,0, 0,0,5},
        {2,4,0, 0,0,0, 3,9,0},
        {5,0,0, 0,0,1, 0,0,2},

        {0,2,5, 0,0,4, 6,0,0},
        {0,0,9, 0,3,0, 0,5,0},
        {0,1,0, 5,6,8, 0,2,0}
    };


    for (int i=1; i<9; i++){
        if (N==S[0][i]){
            Valido = false;
        }
    }

    for (int a=1; i<9a++){
        if(N==S[a][0]){
            valido = false; 
        }
    }

    

}

/*


*/