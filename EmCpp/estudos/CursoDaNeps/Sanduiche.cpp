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
ainda pensando em dividir em 2 partes, imagina um algoritimo parecido, também em N² mas ao inves de 
procurar somas = D ele acha a maior soma menor ou igual a D dado uma posição i, tipo no caso de [2,2,3,3,2,3]

index ->  0 1 2 3 4 5 
i = 0 -> [(2,2,3),3,2,3] vai pegar os primeiros 3 digitos por que eles são iguais a 7
i = 1 -> [2,(2,3),3,2,3] primeiros 2 digitos por que eles somam 5 e se adicionasse o proximo daria 8
i = 2 -> [2,2,(3,3),2,3]
i = 3 -> [2,2,3,(3,2),3]
i = 4 -> [2,2,3,3,(2,3)]
i = 5 -> [2,2,3,3,2,(3)]

a ideia aqui é: Pra cada indice i, até que j podemos ir sem que a soma ultrapasse D?

Repara que se de i até j a soma é x então de i+1 até j a soma é x-C[i]. 

ou seja, agente só precisa de 2 ponteiros , j sempre anda pra frente e equando a soma
for maior > D movemos i (pra continua somando a partir de i++) e atualizamos a soma 
Soma -= C[i] (isso antes do i++)

Ta, mais falta resolver o outro problema: "Quantos pares i, j existem tal que a soma
C[1]+C[2]... C[i] + C[J] + C[J+1]", acho que a ideia é parecida com a com a outra, tipo agente tem 2 sequencias,
i tem que ser menor ou igual a j, 


*/

int main(){

    int N,D;//Numero de pedaços e Soma
    cin >> N >> D;

    vector<int> C; //Comprimento dos pedaços
    for (int i=0; i<N;i++){
        int c;
        cin >> c;
        C.push_back(c);
    }



    //1 2 3 4 3-> valor
    //0 1 2 3 4 -> index
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

    */
    int resposta=0;
    int soma =0;
    int i =0;
    for (int j = 0; j<N; j++){
        soma+=C[k];
        while (soma > D){
            soma-=C[i];
            i++;
        }
        if (soma == D){
            resposta++;
        }
    }


    cout << resposta;
    return 0;
}