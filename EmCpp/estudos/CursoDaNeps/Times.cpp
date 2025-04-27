//https://neps.academy/br/course/fundamentos-das-estruturas-de-dados/lesson/times

/*


*/


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
A logica aqui é sortear o vetor em Log n, ou seja cada indice vai sendo adicionado
já de forma sorteada ai depois é so ir pegando do topo e adicionar aos times

*/

int main(){
    int N,T;//numero de pessoas e de times
    cin >> N >> T;

    vector<string> nomes;
    vector<int> habilidades;
    for (int i=0; i<N; i++){
        string nome;
        int habilidade;
        cin >> nome >> habilidade; 

        habilidades.push_back(habilidade);
        nomes.push_back(habilidade);

        for (int i=0;i<habilidades.size();i++){
            cout << nomes[i] << " " << habilidades[i] << endl;
        }
        
    }


    vector<vector<string>> Times(3,vector<string>());

    return 0;
}

