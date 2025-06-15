//  https://neps.academy/br/course/estrategias-avancadas-de-programacao/lesson/troca
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
 Existe uma sequência de N cartas com um numero em cima e outro em baixo. depois de virar
 as cartas varias vezes como fica? Pra fazer isso eu poderia  criar um vetor bool com a orientação e ir mudando
 tipo:
    vector<bool> orientacao(N,true);
    for (int i=0; i<T; i++){
        int a, b; cin >> a >> b;
        //troca(1,3) muda os indice 0,1,2
        for (int i = a-1;i<b;i++){
            orientacao[i] = !orientacao[i];
        }
    }

    mas e se ao inves disso eu processar tudo de uma vez? tipo olha esse par de trocas:
    1 3 (index 0 1 2)
    5 10 (index 4 5 6 7 8 9)
    2 6 (index 1 2 3 4 5)
    5 9 (index 4 5 6 7 8)
    1 7 (index 0 1 2 3 4 5 6 7)

    eu posso salvar esses vetor em uma matrix, e depois somar todo... Mas ainda fica com
    for (int i = a-1;i<b;i++){

    talvez um jeito de preprocessar a entrada

    Eu poderia ter um vetor de tamanho N, e guardar quantas vezes a aparece e quantas vezes
    b aparece. Tipo cada troca vai de a-1 até b-1 (contando com b-1). Melhor, vamo usar 1-based
    então cada troca meche nos indices, a, a+1, ..., b. Basta criar um vetor marcando +1 pra a
    e -1 pra b+1:
    vector<int> Psum(N+2,0);
    Psum[0] = 0;
    for (int i=1; i<=T; i++){
        int a, b; cin >> a >> b;
        //troca(1,3) muda os indice 1 2 3 (1-based)
        Psum[a]++;
        Psum[b+1]--;
    }

    e depois 
    int saldo =0;
    for(int i =1; i<=N; i++){
        saldo += Psum[i];
        if (saldo % 2 == 0) {
            cout << cima[i] << " ";
        } else {
            cout << baixo[i] << " ";
        }
    }

    Repara que o b+1 é porque troca (3,5) deve mecher nos indices 3,4,*5* como o 5 ta incluido o -1 vai pra frente dele
    */

int main(){

    int N, T; cin >> N >> T; //N, numero de trocas

    vector<int> cima(N+1);
    for (int i=1; i<=N; i++){
        cin >> cima[i];
    }

    vector<int> baixo(N+1);
    for (int i=1; i<=N; i++){
        cin >> baixo[i];
    }

    vector<int> Psum(N+2,0);
    Psum[0] = 0;
    for (int i=1; i<=T; i++){
        int a, b; cin >> a >> b;
        //troca(1,3) muda os indice 1 2 3 (1-based)
        Psum[a]++;
        Psum[b+1]--;
    }

    int saldo =0;
    for(int i =1; i<=N; i++){
        saldo += Psum[i];
        if (saldo % 2 == 0) {
            cout << cima[i] << " ";
        } else {
            cout << baixo[i] << " ";
        }
    }
    return 0;
}