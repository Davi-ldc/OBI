#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
 0  1  2  3  4  5
{1, 2, 3, 4, 5, 6}
meio é inicio (0) + fim (5) / 2 = 2
se eu tivesse considerando só 2, 3, 4, 5, 6 
então o meio seria  inicio(1) + fim (5) / 2 -> 3

perceba que (inicio+fim)/2

tambem pode ser escrito como:
inicio + (fim - inicio)/2

já que  (x+y)/2 = x/2 + y/2 = (x - x/2) + y/2 = x + (-x/2 + y/2) = x+(y-x)/2

*/


//junta 2 partes de uma lista ordenada
//a primeira parte vai de inicio até meio
//a segunda parte vai de meio + 1 até fim
void merge(vector<int>& V, int inicio, int meio, int fim){
    vector<int> esquerda(V.begin() + inicio, V.begin() + meio + 1);
    vector<int> direita(V.begin() + meio + 1, V.begin() + fim + 1);

    //ponteiro da esquerda, direita e vetor original
    //inicialmente, ponteiros apontam para o inicio de cada vetor
    int i = 0, j = 0, k = inicio;

    //enquanto houver elementos em ambas as metades
    while(i < esquerda.size() && j < direita.size()){
        //se o elemento da esquerda for menor ou igual ao da direita
        //coloca o elemento da esquerda no vetor original
        if(esquerda[i] <= direita[j]){
            V[k++] = esquerda[i++];
        } else {
            //caso contrário, coloca o elemento da direita no vetor original
            V[k++] = direita[j++];
        }
    }

    //se sobra numeros coloca no final
    while(i < esquerda.size()){
        V[k++] = esquerda[i++];
    }

    while(j < direita.size()){
        V[k++] = direita[j++];
    }
}

void mergeSort(vector<int>& V, int inicio, int fim){
    if(inicio >= fim) return; //caso base
    //se inicio = fim, só tem um elemento
    //se for maior que fim, a lista ta vazia

    //mesma coisa que (inicio + fim) / 2
    int meio = inicio + (fim - inicio)/2;

    mergeSort(V, inicio, meio); //esquerda
    mergeSort(V, meio + 1, fim); //direita

    //chamar a função de merge
    merge(V, inicio, meio, fim);
    
}


int main(){

    int N; cin >> N;

    vector<int> V(N);
    for(int i =0; i < N; i++){
        cin >> V[i];
    }

    mergeSort(V,0,V.size()-1);

    for(int i=0; i < N; i++){
        cout << V[i] << " ";
    }
    
    return 0;
}