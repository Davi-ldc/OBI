//https://neps.academy/br/course/fundamentos-das-estruturas-de-dados/lesson/apagando-e-ganhando

#include <iostream>
#include <bits/stdc++.h>

int main(){

    /*
    A sacada aqui é que agente tem que tirar os menores numeros
    da esqueda pra direita. Melhor, da pra ir adicionando

    Ou eu poderia adicionar os maiores números em uma pilha, tipo dar
    um sort
    1 2 3 1 2 3
    se fosse um vetor já sorteado
    
    */

    int D=0;
    int N=0;
    vector<int> pilha;
    int i =0;
    while (D!=0 && N!=0){
        cin << pilha[i];
        i++;
    }
    return 0;
}