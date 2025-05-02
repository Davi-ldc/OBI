//https://neps.academy/br/course/fundamentos-das-estruturas-de-dados/lesson/times

/*


*/


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
A logica aqui é sortear o vetor em N Log n e depois sortear por ordem alfabetica cada um dos times,
nada de mais :)
*/

int main(){
    int N,T;//numero de alunos e de times
    cin >> N >> T;

    vector<pair<string,int>> alunos;
    for (int i=0; i<N; i++){
        string nome;
        int habilidade;
        cin >> nome >> habilidade; 

        alunos.push_back({nome, habilidade});
    }

    sort(alunos.begin(), alunos.end(), [](auto A, auto B){
        // se A for maior que B então A vem primeiro
        //Ou seja, os maiores valores vem primeiro e o vetor está ordenado de forma decrescente
        return A.second > B.second;
    });

    //debug
    // for (auto p : alunos){
    //     cout << p.first << " " << p.second << endl;
    // }

    //T vetores<string> vaizos
    vector<vector<string>> times(T,vector<string>());
    
    for (int i=0; i<alunos.size();i++){//Vou botando o com maior habilidade no time 1, depois no 2, no 3 e repete
        times[i%T].push_back(alunos[i].first);
    }

    //sorteia cada vetor de times em ordem alfabetica
    for (int i =0;i<times.size();i++){
        sort(times[i].begin(),times[i].end());
    }

    for (int i=0;i<times.size();i++){ //loop pra cada time
        cout << "Time " << i+1 << endl;//i+1 por que não tem time 0
        for (int j=0; j<times[i].size();j++){ //imprime cada string
            cout << times[i][j] << endl;
            if(j==times[i].size()-1){
                cout << endl;//se for a ultima da um \n a mais
            }
        }
    }

    return 0;
}

