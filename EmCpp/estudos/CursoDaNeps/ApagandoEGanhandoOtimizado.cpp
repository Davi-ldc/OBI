//https://neps.academy/br/course/fundamentos-das-estruturas-de-dados/lesson/apagando-e-ganhando

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    /*
    A sacada aqui é que agente tem que tirar os menores numeros
    da esqueda pra direita. Melhor, da pra ir adicionando

    Ou eu poderia adicionar os maiores números em uma pilha, tipo dar
    um sort
    1 2 3 1 2 3
    se fosse um vetor já sorteado
    
    */

    int N=0,D=0;

    while (true){
        cin >> N;
        cin >> D;

        if(D == 0 && N == 0){
            break;
        }

        vector<int> digitos;


        string num;
        cin >> num;
        for (char c : num){
            digitos.push_back(c-'0');
        }

        /*
        tipo, imagina o numero 123. 123%10 =3 e 123 divisão inteira por 10 é 12
        */
        

        vector<int> pilha;
        pilha.push_back(digitos[0]);
        /* A grande sacada aqui é perceber que pra cada número que ele for remover
        o melhor é focar no digito mais a esquerda. Por exemplo, no numero 123123
        Se D=1 a prioridade deve ser o primeiro e segundo digito, depois o segundo e o terceiro
        já que eles vão ter maior influencia no resultado final (Eu sei que é obvio falando mais demora pra perceber)

        Com essa ideia em mente, criamos uma pilha, só com o primeiro digito e ai pra cada digito seguinte é so 
        chechar se ele é maior que o anterior. Se for e D>0 então devemos remover o anterior. Se não for maior
        então só adicionamos ele a pilha, fazendo com que ele seja a nova prioridade.
        */
        for (int i=1; i<digitos.size();i++){
            
            while(!pilha.empty() && pilha.back() < digitos[i] && D >0){
                pilha.pop_back();
                D--;
            }
            pilha.push_back(digitos[i]);

        }

        //para casos como 100000 é so remover do final
        while(!pilha.empty() && D>0 ){
            pilha.pop_back();
            D--;
        }

        //debug
        for (int a: pilha){
            cout << a;
        }
        cout << endl;
    }

    return 0;
}