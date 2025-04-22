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

    A ideia para fazer isso em N log N é: Ir salvando cada indice que agente olhou.
    Como o set deixa em ordem de valor crescente é só achar o indice do primeiro 
    número maior que o atual. Tipo se o set tem 5 números e o primeiro número 
    maior que o atual está no indice 2 então tem 5-2 = 3 números restantes que 
    podem virar duplas 
    */



    set<int> vistos;
    for (auto& [valor, indice] : S) {

        int start = 0;
        int end = vistos.size()-1;
        int v = valor
        int index = vistos.size(); //se não achar retorna o tamanho por que ai vistos.size()-index é 0 
        //ou seja nenhhuma duplas

        // acha o index do primeiro número maior que o atual
        while (start <= end) {
            int mid = (start + end)/2;//repara que é uma divisão inteira,
            //então se start é 5 e end 6, por exemplo, mid vai ser 11/2 -> 5,5
            //mas sem a parte fracionária então fica 5
            
            if (vistos[mid] > valor) //se o valor for maior, salvamos ele
                index = mid;
                end = mid - 1; //depois de salvar mudamos a lista para todos os valores a esquerda dele
            } else {
                // Se for menor ou igual, procura à direita
                start = mid + 1;
            }
        }

        //se eu sei que o primeirno numero maior que o atual está no index x do set ordenado, então
        //eu sei que tem (vistos.size()-x) números maiores que o atual
        Duplas += vistos.size() - index ;//

        vistos.insert(indice);//O set deixa sorteado automaticamente

        // cout << "vistos = { ";
        // for (int v : vistos) {
        //     cout << v << " ";
        // }
        // cout << "}" << endl;
    }
    cout << Duplas;


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