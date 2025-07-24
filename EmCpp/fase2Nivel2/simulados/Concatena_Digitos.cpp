//https://neps.academy/br/exercise/2795
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Exemplo classico de soma de prefixos
/*
A gente tem uma lista tipo A B C D E 

No caso de 1,2,3 o potencia da lista é a soma de todas as combinações de 2 dígitos possiveis
nesse caso é:
1->2
1->3
2->1
2->3
3->1
3->2

Repara que o numero de combinações é N*(N-1) já que cada numero gera n-1 possibilidades 
tipo 1,2
1->2
2->1

Minha ideia é ter um vetor prefix[n] que calcule o potencial de Vetor[0] até Vetor[N]

1 1 2 3 9
1 3
1 5
2 4
3 3

potencial de cada-> 
0 - 1 
22 - 2
88 - 3
231 - 4
704 - 5

e se e eu quiser do 2 até o 4
o 2 representa
1->2
2->1


o 4 representa -> (4*4-1->4*3 = 12 possibilidades)
1->2
1->3
1->4
2->1
2->3
2->4
3->1
3->2
3->4
4->1
4->2
4->3

Agora de 2->4 temo que tirar todas as aparições do 1.
isso é igual ao prefix[4] - 1->2 1->3 1->4 a questão é como eu precalculo esse cara 
E se ele quisesse de 3 até 4? ai também teriamos que tirar 1->3 2->3 4->3
Tavendo que cada um é prefix[4]-alguma coisa? 

E se o prefixo, na verdade fosse todas as aparições de um numero. tipo assim prefix[2] é 
2->1 2->3 2->4 2->5... Mas e se ele quisesse são até 4, ai nao precisaria tirar 2-5

O chato é que prefix 3 nao ta na mesma reta que 4 pra você poder achar um pedaço com r-l
Mas... o que L-R representa. Tipo 3->4 prefix[4] - prefix[3] é o que? 

sobra 1->4 2->4 3->4 4->3, ou seja o 4 com todos os outros numeros. Mas o correto seria

4->3
3->3
sem esses 2 caras: 1->4 2->4


mas no caso de Tipo 2->4 prefix[4] é
1->2
1->3
1->4
2->1
2->3
2->4
3->1
3->2
3->4
4->1
4->2
4->3

prefix 2 é : 
2->1
1->2

o correto seria essas 6 (tirando  1->3 1->4, 3->1, 4->1) 
2->3
2->4
3->2
3->4
4->2
4->3

mas sobram:

1->3
1->4
2->3
2->4
3->1
3->2
3->4
4->1
4->2
4->3

fica faltando deletar 1->3 1->4, que nao ta em prefix 2
Vamo pensar em generalizar. Eu sei quanto vale potencial de N, que inclui N*(N-1) possibilidades
E quero saber quanto vale potencial de L até N (onde L<=N);

potencial de L está obrigatóriamente dentro de N mas vai ficar faltando tirar as aparições de
1,2...L-1 com L+1, L+2... L+N

Se fosse 3-4 (ultimo):
prefix 3 (3*2)->6
1->2
1->3
2->1
2->3
3->1
3->2
prefix 4: 
1->2
1->3
1->4
2->1
2->3
2->4
3->1
3->2
3->4
4->1
4->2
4->3

prefix 4-3:
1->4
2->4
3->4
4->1
4->2
4->3

Só falta tirar 1->4 ,2->4, 4->1, 4->2

se fosse 3-5

1->4, 1->5; 2->4, 2->5
4->1, 5->1; 4->2, 5->5 
*/

int main(){

    //numero de digitos na lista e numero de perguntas
    int N, Q; cin >> N >> Q;

    vector<int> V(N+1);//1 based é mais facil para nos meros humanos mortais
    for (int i =1; i<=N; i++){
        cin >> V[i];
    }

    vector<int> prefix(N+1);
    prefix[0] = 0;
    prefix[1] = 0;//Um número sozinho nao pode ser concatenado
    // prefix[2] = (V[0]*10 + V[1]) +  (V[1]*10 + V[0]);//primeiro com segundo + segundo com primeiro
    
    int potencial = 0;

    /*A partir do terceiro, quando adicionamos um digito temos que adicionar */
    /*Esse digito com o primeiro, o segundo... + prefix anterior
    */
        for (int i =2; i<=N; i++){
            for(int j = 1; j<i; j++){
                //numero novo com o numero antigo
                potencial += V[i]*10+V[j];
                //numero antigo com numero novo
                potencial += V[j]*10+V[i];
            }
            prefix[i] = potencial;
        }

    /*
    Eu sei quanto vale potencial de N, que inclui N*(N-1) possibilidades
    E quero saber quanto vale potencial de L até N (onde L<=N);

    potencial de L está obrigatóriamente dentro de N mas vai ficar faltando tirar as aparições de
    1,2...L-1 com L+1, L+2... N

    1->3 1->4 se fosse de 3-4 ai tambem faltaria 3->1 3->2

    3->4
    4->3
    de 1 até L-1 com L+1
    tipo se fosse 3-5
    1->4, 1->5; 2->4, 2->5 (e o inverso)

    se for 2-4:
    1->3, 1->4, ou seja 1 até L-1 com L+1 e L+2 até R
    */
    vector<pair<int,int>> P(Q);
    for (int i =0; i < Q; i++){
        int L, R; cin >> L >> R;
        P[i] = {L,R};
    }

    for (int i =0; i < Q; i++){
        int L = P[i].first;
        int R = P[i].second;
        int resposta = 0;
        if(L==R){
            cout << resposta;
            continue;
        }
        resposta = prefix[R]-prefix[L];//salva um pouco.
        //L-1
        for (int j =1; j<=L-1;j++){//tipo se L for 3 tem que tirar 2 e 1 e R for 5
            for (int k=L+1; k<=R; k++ ){// com 4 e 5
                //1->2, 1->3 e o inverso 2->1 3->1...
                resposta -= (V[j]*10+V[k]) + (V[k]*10+V[j]);
                // cout << j << "->" << k << ", ";
            }
        }

        cout << resposta << endl;
    }


    
    return 0;
}

/*

5 2
1 1 2 3 9
2 4
3 5
*/