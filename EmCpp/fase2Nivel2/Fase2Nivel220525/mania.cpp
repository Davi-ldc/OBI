#include <iostream>
#include <bits/stdc++.h>
#define int long long

using namespace std;
/*
3 3
1 2 1
2 2 2
1 2 1

1 2 1
2 3 2
1 2 1

repara que tds as diagonais são impares, no caso o inverso das outras,
as diagonais são posições impares, meio que td cara tem que tar cercado de alguem oposto (menos na diagonal)
pq impar + par -> impar e par +impar tmb 

1 5 
1 2 3 4 5
impar par i p i p.... ou o inverso


*/

signed main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> matriz(N, vector<int>(M));
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> matriz[i][j];
        }
    }
    
    // ent tem 2 opções, quem tem i+j  par ter valor par e i+j impar ter v impar
    int opc1 = 0; 
    //OUU o oposto 
    int opc2 = 0; 

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int valor = matriz[i][j] % 2;//(par ou impar)
            int pos = (i + j) % 2;
            
            if(pos == 0 && valor == 1) {
                opc1++;
            }
            if(pos == 1 && valor == 0) {
                opc1++;
            }
            if(pos == 0 && valor == 0) {
                opc2++;
            }
            if(pos == 1 && valor == 1) {
                opc2++;
            }
        }
    }

    int resposta = min(opc1, opc2);
    cout << resposta << endl;
    
    //Ai altera a matriz
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int valor = matriz[i][j] % 2;
            int pos = (i + j) % 2;
            
            if(resposta == opc1) {
                if(pos == 0 && valor == 1) {
                    matriz[i][j]++;
                }
                if(pos == 1 && valor == 0) {
                    matriz[i][j]++;
                }
            } else {
                if(pos == 0 && valor == 0) {
                    matriz[i][j]++;
                }
                if(pos == 1 && valor == 1) {
                    matriz[i][j]++;
                }
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << matriz[i][j];
            cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
