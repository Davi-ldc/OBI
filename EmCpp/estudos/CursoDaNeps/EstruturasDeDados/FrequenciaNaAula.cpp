//https://neps.academy/br/course/fundamentos-das-estruturas-de-dados/lesson/frequencia-na-aula

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
é o mais facil que eu já fiz até agora, ele te da varios numeros
e quer saber quantos numeros unicos tem. A sacada aqui é só saber que um map 
não permite chaves duplas, e que o insert só vai adicionar a chave se ela não
existir. (Se a chave já existir o insert não troca o valor e não insere nada)

então é só ir add no map e printar o size dps
*/

int main(){

    map<int,int> frequencia;

    int N; //quantidade de numeros
    cin >> N;
    for (int i=0;i<N;i++){
        int V;
        cin >> V;
        frequencia.insert({V,0});
    }
    cout << frequencia.size();
}