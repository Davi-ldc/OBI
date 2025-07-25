//https://neps.academy/br/exercise/2795
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
A sacada aqui é perceber que cada par contribui com  
V[i]*10 + V[i] tipo, no caso 1 2 3

12 + 13 + 21 + 23 + 31 + 32 = 132

o 1 aparece em 12 e 13 então a contribuição dele é 20 e ao mesmo tempo aparece em 21 e 31
logo, a contribuição de um numero N para a lista de X elementos é
(centenas)   (unidades)
10*N*(X-1) + (X-1)*N 
fatorando, a contribuição é (X-1)*N*(10+1)

então nesse caso onde L=1 R=3 
12 + 13 + 21 + 23 + 31 + 32 = 132
L=2 R=3 

(12 + 13 + 21 + 23 + 31 + 32) - 31 - 21 - 12 -13

A gente poderia calcular a contribuição de todos os numeros pralista toda, tipo no caso do 1 é 
10*1*2 + 2*N
O intervalo todo vai ser a soma de todas as contribuições. tipo se os numeros são
A B e C 
(X-1)(10+1)*A + (X-1)(10+1)*B + (X-1)(10+1)*C OPAAAAA isso é igual a
(X-1)(10+1)(A+B+C) BUMM da pra prefixar isso aqui, a contribuição de A, A com B, A com B com C

tipo voltando a 1 2 3 
12 + 13 + 21 + 23 + 31 + 32 = 132

A contribuição do 1 é 10*1*2 + 2*1 aka 10*A*(X-1)+(X-1)*A = 20+2
a contribuição do 1 com o 2 é contribuição do 1 + 10*A*(X-1)+(X-1)*A -> 22 + 40 + 4
a contribuição do 1 com o 2 é contribuição do 2 + 10*A*(X-1)+(X-1)*A-> 66 + 60 + 6 = 132. 
mas se eu quiser só de 2 até 3 isso é o mesmo que pedir o potencial de 2,3, ou A,B
e o potencial de A,B,C,...args é (X-1)(10+1)(A+B+C+args)

2 5

495

*/

long long potencial(vector<long long>& P, long long L, long long R){
    /*
    ----------L----------------R
    distancia(L,R) é intuitivamente R - L  
    */
    //(A+B+C+args)
    //tipo se eu quiser de 2-5 a soma vai dar P[5] (15)- P[2](3) = 12
    long long soma = P[R]-P[L-1];

    //Tamanho da lista tipo se V original for 1 2 3 4, L for 1 e R for 3 então ele que o potencial
    //de 1,2,3 logo R-(L-1)
    //tipo 2-5 (potencial de 2,3,4,5)
    //5-2-1
    long long X = R-(L-1);//4

    //(X-1)(10+1)(A+B+C+args)
    return (X-1)*(10+1)*(soma);
}

main(){
    
    long long N,Q; cin >> N >> Q;

    vector<long long> V(N+1);//1-based é mais facil
    for (long long i=1; i<=N; i++){
        cin >> V[i];
    }

    vector<long long> prefix(N+1);
    prefix[0] = 0;
    for (long long i=1; i<=N; i++){
        //V = 1,2,3
        //prefix de V[2] é 1 + 2, prefix[3] = prefix[2] + V[3];
        prefix[i] = prefix[i-1] + V[i];
    }

    vector<pair<long long,long long>> perguntas(Q);
    for (long long i =0; i<Q; i++){
        long long L, R; cin >> L >> R;
        perguntas[i] = {L,R};
    }

    for (auto p : perguntas){
        cout << potencial(prefix,p.first,p.second) << endl;
    }

}

/*
5 4
1 2 3 4 5
1 3
1 5
2 4
1 1
*/