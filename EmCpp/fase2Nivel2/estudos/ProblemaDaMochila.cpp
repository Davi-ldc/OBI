//https://neps.academy/br/course/estrategias-avancadas-de-programacao/lesson/o-problema-da-mochila

#include <iostream>
#include <bits/stdc++.h>
#define int long long

using namespace std;

/*
A pergunta é simples. Qual é a maior capacidade possivel? O segredo aqui é imaginar uma matriz
//tipo olha essa entrada
4 10//4 itens, capacidade 10

3 4 //peso, valor A
8 2// B
5 4// C
4 3// D

A sacada pra resolver é analisar como cada item novo muda o que sabemos, tipo, intuitivamente
o valor máximo pra uma capacidade 0 é 0. Mas e se eu adicionar um item 8, 2
bem nesse caso, ele só influencia no valor pra uma capacidade => 8 e pra capacidade 8 por exemplo
2 vai ser o maior valor se dp[8] for menor que 2. Mas e pra dp[9]? Bem, se o valor máximo pra uma 
capacidade 1 é dp[1] então o máximo pra dp[9] (analisando esse item novo) vai ser dp[1] + valor atual
dp[i] = dp[i-8] + valor atual 

tipo "qual o maior valor V pra capacidade 10?" como esse elemento gasta 8, é o valor dele + 
dp[10-8]

Formalizando, dp[i] = dp[i-Peso] + Valor; Ai tem que checar se esse novo máximo é maior que o anterior
*/


main(){

    int N, C; cin >> N >> C;//numero de itens e capacidade da mochila 

    vector<pair<int,int>> PV(N);//peso,valor
    for (int i=0;i<N;i++){
        int p,v; cin >> p >> v;

        PV[i] = {p,v};
    }

    //1 based XD 
    vector<int> dp(C+1,0);//O valor maximo pra qualquer capacidade começa em 0
    for (pair par: PV){
        //pra cada par
        int p = par.first;
        int v = par.second;
        int i = C;//capacidade da mochila
        while (i>=p){//tipo se o peso é 8 não influencia no maior valor pra capacidade 2 logo a gente só analisa até capacidade>=peso
            //"qual o maior valor pra uma capacidade i? Ora é o maior valor de i-pesoatual + valoratual"
            int valor = dp[i-p]+v;
            if (valor > dp[i]){
                dp[i] = valor;
            }
            i--;
        }
        //repara que o loop é de tras pra frente pro resultado nao interferir no processo
    }

    //valor mmáximo pra C
    cout << dp[C];
}