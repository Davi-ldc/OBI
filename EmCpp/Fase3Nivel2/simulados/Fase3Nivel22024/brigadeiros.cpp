#include <iostream>
#include <bits/stdc++.h>
#define int long long

using namespace std;

/*
i é o prato q vc ta j é o amigo q vc ta

Ai eu tenho que pensar qual o menor t para uma posição 

tipo:
1 2 3 4 5 6 //index pra visualizar XD
9 8 4 1 4 10
0 1 0 1 0 0

* partindo do principio de que na resposta final eles vao ter que estar na mesma ordem e que
* o custo de andar até uma posição é abs(posiçãoinicial-final)

eu vou iterar da esquerda pra direita pensando "qual o menor t para n brigadeiros?"
dp[i][j][c] com o custo mínimo para que os j primeiros amigos peguem c brigadeiros considerandos os primeiros i pratos da mesa 


ai analizando da esquerda pra direita eu posso pegar ou não cada prato 

dp[1][1][9] = abs(1-2) = 1;

ta ai passando pra frente dp[2][1] tenho 2 opções, pegar ou não o prato; Se eu não pegar o custo é o mesmo 
logo dp é dp[i-1][j][c]; mas se eu decidir pegar um prato...
os amigos vão estar em ordem, logo os amigos anteriores (j-1) tem que estar em pratos i-1 


os j-1 amigos anteriores já devem ter sido alocados entre os i-1 pratos anteriores, coletando um total de c - P[i] brigadeiros.
O custo para isso é dp[i-1][j-1][c - P[i]]. A esse custo, adicionamos o custo de movimento para o j-ésimo amigo, 
que é a distância entre sua posição inicial e o prato i.

*/

vector<int> p;

main(){
    
    int N, K, T;
    int inf = INT_MAX;

    //N pessoas K amigos T 
    cin >> N >> K >> T;
    //dp[i][j][c] = custo mínimo para que os j primeiros amigos peguem c brigadeiros considerandos os primeiros i pratos da mesa
    //Tem N amigos N pratos e no máximo N*9 brigadeiros (já tem tem entre 0 e 9 brigadeiros )
    int dp[N][N][N*9];

    
    for (int i=0;i<N; i++){
        for(int j=0; j < N; j++){
            for(int k=0;k<N*9;k++){
                dp[i][j][k] = inf;
            }
        }
    }


    for (int i=0; i<N )


}