//https://neps.academy/br/course/fundamentos-das-estruturas-de-dados/lesson/banco

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*

A grande sacada pra essa solução foi ir simulando mentalmente o tempo que faltava pra cada caixa
ficar liberado. Pensa assim, eles começam todos com 0 minutos para serem liberados por que estão vazios
Ai, quando alguem chegar ele vai ir no caixa que falta menos tempo, e assim por diante. Então precisamos
saber qual o caixa que vai ser liberado primeiro. Isso é o que falta menos tempo pra ser liberado.
Então eu acho o index dele, e adiciono o tempo que a pessoa precisa pra ser atendida, mas também removo
a diferença de tempo que pessou entre a entrada de 2 pessoas.

Assim conseguimos acompanhar o tempo de cada caixa eletronico.
*/

int QualCaixaDemoraMenos(vector<long long> caixas){
    /*
    Acha o index do menor valor do vetor caixas em O(N)
    */
    if (caixas.size()==1){
        return 0;
    }
    int index = 0;
    long long menorValor = 1e18;//1 vezes 10 elevado a 18
    for (int i=0;i<caixas.size();i++){ //repara que se tiver 2 iguais retorna o primeiro
        if (caixas[i] < menorValor){
            menorValor = caixas[i];
            index = i;
        }
    }
    return index;
}

int main(){

    int C,N;//numero de caixas, numero de pessoas
    cin >> C >> N;

    vector<pair<int,int>> pessoas;

    for (int i=0; i<N; i++){
        int T, D;//hora em que entrou na fila, tempo de demora
        cin >> T >> D;
        pessoas.push_back({T,D});
    }

    //tempo que falta pra eles ficarem livres
    vector<long long> caixas(C);

    int resposta = 0; //numero de pessoas que demoraram mais de 20m pra serem atendidas
    int TGlobal =0;
    for (int i=0;i<pessoas.size();i++){ 
        //precisamos ir olhando o vetor pessoas a partir de C
        //primeiro agente descobre qual o caixa que vai demorar menos
        //calculamos o tempo de espera. Atualizamos os tempos dos caixas

        int index = QualCaixaDemoraMenos(caixas); 

        // A gente sabe quanto tempo faltava pra cada caixa ser liberado pro cara anterior
        // então, se pro cara que chegou quando T=3 faltava 7m 
        //pro cara que chegou em T=5 falta 7 - (5-3) minutos
        if(i>0){
            int tempoDeEspera = caixas[index] - (pessoas[i].first - pessoas[i-1].first);
            if (tempoDeEspera > 20){
                resposta++;
            }
        }


        //debug
        // cout << "iteracao " << i << " tempos ";
        // for (int x : caixas){
        //     cout << x << " ";
        // }
        // cout << "menor caixa ta no indice " << index << ' ';
        // cout << " tempo de espera " << tempoDeEspera << endl;
        // cout << endl;


        //atualiza com as diferenças. Agente sabe que passou pessoas[i].first - pessoas[i-1].first minutos
        //entre a entrada de pessoas[i-1] e pessoas[i]; Então o tempo de todos os caixas é - esse valor
        //e o caixa em que a proxima pessoa for entrar recebe a mais o tempo que ela demora pra ser atendida
        if(i > 0){
            TGlobal = pessoas[i].first - pessoas[i-1].first;
        }
        for (auto& c : caixas){
            c = max(c-TGlobal,0LL);//garante que não seja negativo; 0LL por que C é LL
        }

        //Quando alguem for pro caixa o tempo pra ele ser liberado aumenta
        caixas[index] += pessoas[i].second;
    
    }
    

    cout << resposta;
    
    return 0;
}