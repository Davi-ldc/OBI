// https://neps.academy/br/course/estrategias-avancadas-de-programacao/lesson/eu-aprendi-busca-binaria

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
A ideia original é, você tem um vetor **ordenado** e quer achar o indice de algum valor tipo:
{0,1,2,3,4,5,6,7} valor desejado (x) = 7

e para resolver o problema vai dividindo o vetor na metade, tipo se o V[meio] > x então x está entre
[inicio, meio-1]; se V[meio] < x então o valor esta entre [meio+1, final]. A implementação classica é

int search(vector<int> V, int x){
    int i = 0;//primeiro
    int j = V.size()-1;//ultimo

    while (i<=j){//enquanto i for <= j
        int meio = (i+j)/2;//calcula o meio
        if(V[meio] == x) {return meio;}//checa ele
        else{
            if(V[meio]>x){
                j = meio -1;//se for maior muda o intervalo para [inicio, meio-1]
            }
            else{ 
                i = meio +1;// se for menor muda pra [meio+1, final]
            }
        }
    }

    return -1;
}

*/

//Mas eu prefiro implementar com ponteiros assim->
int search(vector<int> V, int x){
    //primeiro numero > x, se não achar retorna x.end()
    auto i = upper_bound(V.begin(), V.end(), x);

    //se o primeiro numero maior que o valor desejado for V.begin() então x não esta em V
    if (i != V.begin() && *(i-1)==x){
        
        return (i-1) - V.begin(); //distancia entre o primeiro elemento e o elemento que é igual a x
        //equivale a indice do elemento que é igual a x
    }
    return -1;
}

int main(){

    int N; cin >>N;
    vector<int> V(N);
    for (int i=0;i<N;i++){
        cin >> V[i];
    }

    int Q; cin >> Q;
    vector<int> Resposta(Q);
    for(int i=0;i<Q; i++){
        int temp; cin >> temp; 
        Resposta[i] = search(V, temp);
    }

    for (int x : Resposta){
        if (x!=-1){cout << x << endl;}
        else { cout << "X" << endl; }
    }
}