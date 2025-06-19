#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
Agente que os pares i,j cujo a soma dos itens de i até j sejam = D OUU
que item[1]+item[2] até item na posição i + item na posição j + item na posição j + 1 até N (o final)
também sejam iguais a D

5 10
1 2 3 4 3

Nessa entrada por exemplo, eu poderia checar 1+2 1+2+3 1+2+3+4... tá aqui resposta ++ e não precisa checar com
o ultimo elemento (já que vai passar de D) mas depois eu preciso testar 2+3 2+3+4 2+3+4+3 até que a soma seja >D
ou acabe a lista. O que é N²/2

Já o negocio das bordas é mais complexo por que é como se fosse a soma de 2 sequencias. a soma da sequencia da 
esquerda (que já estamos testando com a logica acima) e a sequencia da direita. o problema aqui é que pra cada
i podem haver C.size()/2 j tipo você se size = 6, você pode pegar (0, 6) (1,5) (1,4) (1,3) (1,2) (1,1)
ou seja fica em N² 

Ta, resolvi em N², mas tem algum jeito mais eficiente,
ainda pensando em dividir em 2 partes da pra fazer 2 ponteiros na primeira parte

*/

int main(){

    int N,S;//Numero de pedaços e Soma
    cin >> N >> S;

    vector<int> C; //Comprimento dos pedaços
    for (int i=0; i<N;i++){
        int c;
        cin >> c;
        C.push_back(c);
    }



    /*
    pensa assim, agente vai ir somando, 1+2 = 3; 3+3 = 6; 6+4 -> 10. Ta 
    agora agente sabe que do index 0 até o index 3 a soma é 10. 
    Quer dizer então que de 1 até 3 a soma é = soma de 0 até 3 - elemento[0];

    Tipo -> 
    [A] + [B] + [C] = 10 
    [B] + [C] = 10 - [A]

    E ai, com essa informalção podemos evitar intervalos desnecessários, tipo se o algoritmo chegou a
    [A] + [B] + [C] + [D] = 15
    Quer dizer que A+B+C é <= 10, Ou seja, não precisamos testar B+C

    A grande sacada aqui é perceber que:
        * Se a soma dos elementos de um vetor C de i até j é x, a soma de i+1 até j é x-C[i]

    (2 ponteiros)
    1 2 3 10 1 1; S = 13
    j = 2 i=0 soma = 6;
    j=3 soma= 16; i++ soma = 15; i++ soma = 13;
    */
    int resposta=0;

    int s =0;
    int i =0;
    int j =0;
    while(j<N){
        s+=C[j];
        while (s > S && i<=j){
            s -= C[i];
            i++;
        }
        if(s == S){
            resposta++;
        }
        j++;
    }

    //parte 2 soma(C[0] até C[i]) + soma(C[j] até C[N-1]) == S
    //map com prefix sums de 
    map<int, int> Pfsum;
    int soma = 0;
    for (int j = N - 1; j >= 1; j--) {  //(não inclui j=0)
        soma += C[j];
        Pfsum[soma]++; //lembrando que se Pfsum[soma] nao existe, ele cria com valor 0
    }

    int somai = 0;
    for (int i = 0; i < N - 1; i++) { // até N-1, porque j > i
        somai += C[i];
        int falta = S - somai;

        if (Pfsum.count(falta))
            resposta += Pfsum[falta];

        // Antes de passar pro próximo i, remove o sufixo que começa em j = i+1
        int remove = 0;
        for (int k = i + 1; k < N; k++) remove += C[k];  // soma de j = i+1 até N-1
        Pfsum[remove]--;
        if (Pfsum[remove] == 0)
            Pfsum.erase(remove);
    }

    cout << resposta;
    return 0;

}