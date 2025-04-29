//https://neps.academy/br/course/fundamentos-das-estruturas-de-dados/lesson/repositorios

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
Esse é bem simples até, cada programa é identificado por um numero unico e tem um valor de versão atribuido

Analizando um exemplo de entrada:
2 5
2000 4 
2001 5 
2000 1
2001 4
2001 6
2000 2
2000 3


As 2 primeiras linhas, são os programas adicionados no computador e as outras 5 linhas são os da intenet.
Repara que como agente só liga pra maior versão, antes de adicionar um par no map precisavamos verificar se
o valor da versão é maior do que o que já está lá. depois so ir imprimindo o par de programas online se
programas no computador [chave] < que programas online[chave]
*/

int main(){
    int C, N; //total de programas instalados, aplicativos e versões disponíveis na internet
    cin >> C >> N; 

    map<int,int> programasC;//nos computadores
    map<int,int> programasO;//online
    vector<pair<int,int>> meImprime;

    for(int i=0; i<C; i++){
        int P, V; //numero do programa e versão
        cin >> P >> V;
        programasC.insert({P, V});
    }

    for(int i=0; i<N; i++){
        int P, V; //numero do programa e versão
        cin >> P >> V;
        if(programasO.find(P) == programasO.end()){// se for um novo
            programasO.insert({P,V});
        }
        else if(V > programasO[P]){ //só adiciona se a versão for a maior
            programasO[P] = V;
        }
    }

    //debug
    // cout << endl;
    // for (auto par : programasO){
    //     cout << par.first << " " << par.second << endl;
    // }

    for (auto par : programasO){//pra cada programa online
        if (par.second > programasC[par.first] ){//checa se a versão online é maior que a atual
            meImprime.push_back({par});
        }
    }

    cout << endl;
    for (auto par : meImprime){
        cout << par.first << " " << par.second << endl;
    }

    return 0;
}