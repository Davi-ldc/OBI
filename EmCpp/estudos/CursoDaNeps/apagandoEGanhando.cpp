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

        vector<int> pilha;


        //nessa questão especifica tem que ler como str (implementação ta na versão otimizada)
        int num;
        cin >> num;
        while (num > 0){//transforma em um vetor
            pilha.push_back(num%10);
            num /=10;
        }
        reverse(pilha.begin(),pilha.end());
        /*
        tipo, imagina o numero 123. 123%10 =3 e 123 divisão inteira por 10 é 12
        */
        


        for (int i=0; i<D; i++){
            if (pilha.empty()){
                break;
            }
            int index = 0;
            int menor = pilha[0];
            for (int c=1; c<pilha.size();c++){
                if (pilha[c] < menor){ 
                    index = c;
                    menor = pilha[c];
                }
            }
            pilha.erase(pilha.begin()+index);
        }

        //debug
        for (int a: pilha){
            cout << a;
        }
        cout << endl;
    }

    return 0;
}