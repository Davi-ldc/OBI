//https://neps.academy/br/exercise/536

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,Duplas = 0;
    cin >> N;

    vector<int> L(N); //vetor de tamnho n
    for(int i = 0; i<L.size(); i++){
        cin >> L[i];
    }

    set<pair<int, int>,  greater<>> S;
    for (int i = 0; i < N; i++) {
        int inverted_index = N - 1 - i;
        S.insert({L[i], inverted_index});//começa em N-1 e vai indo até 0
    }


    //poderia fazer isso mas fica em O² ou seja perde todo o sentido do sort
    //Ele olha pra cada numero de baixo e faz uma comparação de index, se for maior
    //duplas ++. Simples intuitivo mas em O²
    // for (int i=0; i<S.size(); i++){
    //     for(int c=0; c<S.size-1-i,i++){
    //         if (S[c].second < S[i].second) Duplas++;
    //     }
    // }

    /*
    Recapitulando, temos o set: (5,3), (4,1), (3,0), (2,2) e (1,4) onde o primeiro número é a habilidade e o
    segundo o tempo que uma bailarina ta na academia, e agente quer saber quantas duplas onde uma delas tem mais
    habilidade e mais experiencia pode ser formada.

    pra cada indice agente checa os que já passaram, sabendo que, como elas estão ordenadas em ordem
    de habilidade decrescente, as bailarinas que já foram vistas tem habilidades maior, então esse indice i que
    estamos checando pode formar uma dupla se sua experiencia (segundo valor dos set) for maior.

    Pra cada interação queremos saber-> Das bailarinas já vistas (mais habilidosas), quantas tem experiencia MAIOR  
    do que a atual? 

    A ideia para fazer isso em N log N é: Como o set por padrão deixa os itens organizados e agente só quer
    adicionar um item, cada adição pode ser feita com busca binária O(logN) e ao inves de comparar todos os valores
    como vistos é um set só com os indices ordenados agente pode só achar um indice menor ou igual ao atual e
    dai pra frente todos vão ser maiores (isso é busca binária então tmb é O(log(N)))   
    */

    set<int> vistos;
    for (auto& [valor, indice] : S) {
        int menores = distance(vistos.begin(), vistos.lower_bound(indice));
        Duplas += menores;
        vistos.insert(indice);//adiciona
        

        // debug
        cout << "vistos = { ";
        for (int v : vistos) {
            cout << v << " ";
        }
        cout << "}" << endl;
    }
    cout << Duplas;

}
/*
A grande sacada aqui é a seguinte, Primeiro perceba que o set já vem sorteado
Se eu tenho a matrix 2x2 com os index inversos :
    5,3
    4,1
    3,0
    2,2
    1,4
e estou em loop por ela, pra cada posição i, como a primeira eu sei que
posso formar dupla com todo valor abaixo de mim que tenha indice menor.
Pra cada número é so olhar pros debaixo e ver quantos tem indice menor
*/