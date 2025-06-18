//https://neps.academy/br/course/estrategias-avancadas-de-programacao/lesson/soma-das-casas

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
A sacada aqui é perceber que só tem um par de valores que somam K. Como o vetor ta ordenado da pra
resolver em o log n pra cada valor x procura por k-x no vetor, se existir imprime
*/

int Bsearch(vector<int> V, int x){
    auto p = upper_bound(V.begin(),V.end(),x);
    if (p!=V.begin() && *(p-1) == x){
        return x;
    }
    return -1;
}

int main(){

    int N; cin >> N;
    vector<int> V(N);
    for (int i=0;i<N;i++){
        cin >> V[i];
    }
    int K; cin >> K; 

    for(int x: V){
        int temp = Bsearch(V,K-x);
        if(temp != -1){
            int a = x>temp ? temp : x;
            int b = x>temp ? x : temp;
            cout << a << " " << b ;
            break;
        }
    }


    return 0;
}