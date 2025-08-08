//https://neps.academy/br/exercise/2438
#include <bits/stdc++.h>
#include <iostream>
#define int long long

using namespace std;

/*
3 2 3 8 5 5 9 
a arbodagem ingenua seria ter um set com o intervalo que estamos atualizando e pra cada
valor novo checa se ele ta no set 

um jeito mas inteligente seria usar 2 ponteiros
j sempre avança então tipo
[3], [3,2] Agora não da pra adicionar o 3 por que ele ja foi adicionado 
logo i tem que ser o index aonde o 3 estava já que intuitivamente se você tem um set
[A B C D E ] e achou C agora o maior que pode formar é D E C 

repara que não precisa armazenar esse vetor D E C só guardar os indices, i j e a cada interção checar
como eles estão tipo
*/

main (){

    int N; cin >> N; 
    vector<int> V(N);
    for (int i=0; i<N; i++){
        cin >> V[i];
    }

    int i = 0;
    int j = 0;
    int resposta =0;
    vector<pair<int,int>> v_i(100000, {0,-1});
    //6    3 2 4 8 5 5 
    while (j<N){
        
        //Se esse valor já existir e estiver dentro da jenela
        if (v_i[V[j]].first && v_i[V[j]].second >= i){
            i = v_i[V[j]].second+1;//i vai ser = lugar onde ele ta +1
        }
        
        //V[j] existe dentro do intervalo
        v_i[V[j]].first = 1;
        //E está na posição J 
        v_i[V[j]].second = j;

        //0,2 -> 3
        //2,4 0> 3
        //3,6 -> 0 1 2 3 4 5 6 (4)->7-3 = 4
        if (j+1-i>resposta){
            resposta = j+1-i;
        }

        j++;
    }
    cout << resposta;
}