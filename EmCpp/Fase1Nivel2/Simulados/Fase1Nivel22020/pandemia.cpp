#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
4 3 -> 4 amigos 3 reuniões
2 1 -> O amigo 2 tava infectado des de a primeira
2 1 2 -> pessoas na primeira reunião 
3 3 1 2 -> pessoas na segunda reunião 
2 2 1 -> pessoas na terceira reunião 

*/

int main(){

    int N, R; //Numero de amigos, Numero de reuniões
    cin >> N >> R;
    
    int ID, PrimeiraReuniãoInfectado; //Tal amigo ta infectado des de a PrimeiraReuniãoInfectado
    cin >> ID >> PrimeiraReuniãoInfectado;

    vector<vector<int>> TodasAsReunioes;

    for (int i=0; i<R; i++){//pra cada reuniao
        int Npessoas;
        cin >> Npessoas;

        vector<int> Reuniao;
        for (int j=0; j<Npessoas; j++){ //pra cada pessoa da reuniao
            int amigo;
            cin >> amigo;
            Reuniao.push_back(amigo);
        }
        TodasAsReunioes.push_back(Reuniao);
    }

    //debug
    // cout << endl;
    // for (int i=0; i<TodasAsReunioes.size();i++){
    //     for (int j=0;j<TodasAsReunioes[i].size(); j++){
    //         cout << TodasAsReunioes[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    set<int> infectados;
    infectados.insert(ID);
    for ( int i=PrimeiraReuniãoInfectado-1; i < TodasAsReunioes.size(); i++){
        for (int j=0; j<TodasAsReunioes[i].size(); j++){
            if (infectados.find(TodasAsReunioes[i][j]) != infectados.end()){//se achou
                for (int k =0; k<TodasAsReunioes[i].size(); k++){
                    infectados.insert(TodasAsReunioes[i][k]);
                }
                break;
            }
        }
    }

    cout << infectados.size();

    return 0;
}


/*
  j 0 1 2
i   
0   1 2 
1   3 1 2 
2   2 1 

*/
