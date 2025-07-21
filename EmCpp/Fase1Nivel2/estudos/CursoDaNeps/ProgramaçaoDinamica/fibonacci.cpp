#include <iostream> 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
A ideia central é bem simples: quando um problema pode ser dividido em subproblemas menores que se repetem, 
ao invés de resolver o mesmo subproblema várias vezes, você resolve uma vez só e guarda o resultado.
Isso se chama memoização. Como no exemplo classico de fibonacci. Pra calular fib (6) ao inves de fazer recursivamente
fib (5)+fib(4) você pode ir construindo a arvore de baixo pra cima, evitanto complexidade e gastando menos memoria

Os dois ingredientes essenciais são:
Subestrutura ótima: a solução do problema maior depende das soluções ótimas dos subproblemas menores.
Subproblemas sobrepostos: os mesmos subproblemas aparecem várias vezes durante a resolução.
(tipo a sequencia de fib)

Geralmente você pode implementar de 2 jeitos: (imagina uma arvore de problemas)
Top-down: de cima pra baixo, resolvendo os problemas conforme eles aparecem e guardando os resultados.
Bottom-up: de baixo pra cima, resolvendo primeiro os subproblemas menores e construindo a solução para o problema maior.
*/

ll fib(ll N){
    
    ll a = 0;
    ll b = 1;
    for (int i =2; i<=N; i++){
        ll temp = a + b;
        b = temp;
        a=b;
    }
    return a;
}

int main(){
    int N;
    cin >> N;
    cout << fib(N);

    return 0;
}