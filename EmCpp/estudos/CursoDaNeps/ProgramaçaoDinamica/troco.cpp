// https://neps.academy/br/course/estrategias-avancadas-de-programacao/lesson/troco

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
Se agente tem as moedas 1,3,4; qual o minimo de moedas que podemos usar para pagar 6 centavos?
Repara que nesse caso pegar a maior moeda não funciona:
(4,1,1) -> solução gulosa
(3,3) -> solução ideal

Ai, você ja lembra de backtraking e pensa em fazer uma busca completa. Testando todos os
subconjuntos, mais isso é O(2^n) e não é viável para n grande tipo:

int sum(vector<int>V){
    int s = 0;
    for (int x : V){
        s+=x;
    }
    return s;
}

//Lista 
void Busca(vector<int> L, int V, vector<int>& Solucao, vector<int>& R, int i){
    if(i == L.size()){
        if (sum(Solucao)==V){
            if(R.empty()){
                R = Solucao;
            }
            else if(Solucao.size()<R.size()){
                R = Solucao;
            }
        }
        return;
    }
    //Pra cada numero de L, podemos adicionar ou não
    Solucao.push_back(L[i]);
    Busca(L,V,Solucao,R,i+1);
    Solucao.pop_back();
    Busca(L,V,Solucao,R,i+1);
    }


    vector<int> Solucao;
    vector<int> R;
    Busca(L, V, Solucao, R, 0);
    if (R.empty()){
        cout << "N";
    }
    else{
        cout << "S";
    }


Funciona mas a versão mais otmizada vem do insght:
se você já sabe quais somas são possíveis com as primeiras i moedas, pode usar essa informação para calcular 
quais somas são possíveis com as primeiras i+1 moedas.
Tipo, tem uma caixa de moedas, e você sabe quais valores pode somar nessa caixa. Ao adicionar uma nova moeda quais
são os novos valores que você pode somar? se tinhamos 1, 2. as somas eram 0, 1, 2 , 3. Ao adicionar uma nova moeda =3
você tambem adiciona as somas -> 3+Soma[0], 3+Somas[1] 3+Somas=[3] 
Poderia ter um vetor com  todas as somas possiveis, mas no caso so importa até a V. Repara que se 
soma[2] é possivel, ao adicionar uma moeda nova soma [6] passa a ser possivel



*/

bool busca(vector<int>& moedas, int V) {
    vector<bool> somas(V + 1, false);

    somas[0] = true;
    for (int moeda : moedas){
        /*
        se soma [2] é possivel, soma [2+moeda] é possivel também. Mas ai você ta editando o vetor durante o loop
        tipo se a proxima moeda for 3, soma [5] vai ser possivel (que vai aparecer depois no loop) levando soma[8] a
        tambem ser considerada possivel. Por isso tem que fazer o loop de traz pra frente

        Tipo ao adicionar a moeda 1, dado V =6
        i = 6 nada i=5 nada ... i = 0
        */
        for (int i=V; i>=0; i--){
            if(i+moeda<=V && somas[i]){
                somas[i+moeda] = true;
            }
            if(somas[V]){
                break;
            }
        }
    }
    return somas[V];
}

int main(){
    int V,N;
    cin >> V >> N;

    vector<int> L(N);
    for (int i=0; i<N; i++){
        cin >> L[i];
    }

    bool x = busca(L, V);
    if (x){
        cout << "S";
    }
    else {
        cout << "N";
    }
    return 0;
}