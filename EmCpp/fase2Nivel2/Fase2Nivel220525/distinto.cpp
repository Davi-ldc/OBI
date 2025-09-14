#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*

2
7 3 7 
8 3 7 

1 10 1 3

4
20 10 11
40 1 10
40 10 20 
5 5 5
*/
int main (){

    int N; cin >> N;
    for (int i =0; i<N; i++){
        long long soma =0;
        long long resposta = 0;
        //A < B 
        long long L, A, B; cin >> L >> A >> B;

        //Ai a logica é bem simples enquanto soma não for >= L soma+= A+j resposta ++
        //Da pra ir fazendo um prefix sum, tipo entre A e B qual o valor maximo que eu posso
        //Mas com while da TLE ... Se eu soubesse a formula da soma daria pra frz um binary search
        while(soma < L){
            long long x = A+resposta;
            if(x>=B){
                resposta++;
                break;
            }
            soma += x;//Por que tem estar entre A e B
            resposta++;
        }
        cout << resposta << endl;
    }
    return 0;
}