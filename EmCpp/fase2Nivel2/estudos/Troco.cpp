//https://neps.academy/br/course/estrategias-avancadas-de-programacao/lesson/troco

#include <iostream>
#include <bits/stdc++.h>
#define int long long

using namespace std;

/*
16 4
25 10 5 1

a ideia é saber se é possivel com essas 4 moedas somar 16. A pergunta é dado um vetor de V elementos
A B C D, eu posso somar um valor S? 
*/

main(){

    //Soma desejada, Número de moedas
    int S, NM; cin >> S >> NM;

    vector<int> moedas(NM);
    for (int i =0; i<NM;i++){
        cin >> moedas[i];
    }

    // sort(moedas.begin(),moedas.end());

    //tamanho S por que não importa saber que é possivel somar algo > S 
    vector<int> dp(S+1,0);//0 -> não podemos somar 1->podemos
    dp[0] = 1;//sempre podemos somar 0
    for (int moeda: moedas ){
        for (int i = S; i>=0; i--){//de traz pra frente pros resultados nao influenciarem no processo
            //Ao adicionar uma moeda nova
            //Se era possivel somar dp[i] antes, agora também é possivel somar 
            //dp [i+valor]
            if(dp[i] == 1 && i+moeda <= S){dp[i+moeda] = 1;}
            if(dp[S]){break;}
        }
        if(dp[S]){break;}
    }

    //se for possivel somar soma
    if(dp[S]){
        cout << "S";
    }
    else {
        cout << "N";
    }

}