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

    //size menos 1 por que não precisa comparar o ultimo número com ninguem
    for (int i = 0; i<L.size()-1; i++){ //Pra cada número menos o ultimo da array
        //menos i evita comparações duplas
        for (int j = 0; j<L.size()-1-i; j++){ //Comparamos ele com os proximos 
            //esse for roda size -1 no primeiro (já que não precisamos comparar um numero com ele mesmo)
            //depois size-2, -3... ai a complexidade fica em N * N/2 
            cout << L[i] << " " << L[i+j+1] << endl;
            if(L[i]>L[j+i+1]){//compara um numero com o adjacente
                Duplas += 1;
            }
        }
    }

    cout << Duplas << endl;

}


//5
//1 5 2 4 3 (5, 2),(5, 4),(5, 3) e (4, 3).
//a primeira deve ser a mais habilidosa e a que frequenta a academia há mais tempo
//então tipo 1 e 5 ta fora pq a que tem habilidade 1 ta a mais tempo
//repara que no exemplo acima tem 2 duplas que não podem ir




/*
imagina uma matrix 2x2 
1  5  2  4  3 Valor 
0  1  2  3  4 Index

O que agente que achar são duplas onde o número é maior e o iníce é
menor. então cada número tem uma dupla se o seu valor e index forem maiores
que o seu adjacente. Repara que depois de comparar todos os numeros com o primeiro
na proxima interação podemos começar a comparar apartir do proximo index
*/