//https://neps.academy/br/course/fundamentos-das-estruturas-de-dados/lesson/troca-de-cartas

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
Esse é relativamente simples, temos 2 conjuntos sorteados
1 3 5
2 4 6 8 
e ele quer saber quantos elementos diferentes tem entre eles. então da pra interar sobre cada 
numero do menor set e ver se ele existe no maior.

A sacadas aqui é perceber que cartas repetidas não importam, por que elas só podem trocar uma delas, tornando o set
ideial pro problema.
OBS-> Pequeno mistake que eu fiz e demorei um tempão pra perceber é que não da pra usar A e B
pra determinar qual o set de tamanho maior por que eles contam as cartas repetidas

*/

int main(){

    int A,B; //numero de cartas de cada uma
    cin >> A >> B;

    set<int> X, Y;
    for (int i =0; i<A; i++){
        int temp;
        cin >>  temp;
        X.insert(temp);//O(logN)
    }
    for (int i =0; i<B; i++){
        int temp;
        cin >>  temp;
        Y.insert(temp);
    }

    // O(1)  A é >= B? Se for Y se não 
    set<int> &maiorSet = (X.size() >= Y.size() ? X : Y);
    set<int> &menorSet =  (X.size() < Y.size() ? X : Y);

    int resposta = 0;
    for (int num : menorSet){//(N log(N))
        if(maiorSet.find(num) == maiorSet.end()){//se o numero não estiver no maior set
            resposta++;
        }
    }

    cout << resposta;
    return 0;
}