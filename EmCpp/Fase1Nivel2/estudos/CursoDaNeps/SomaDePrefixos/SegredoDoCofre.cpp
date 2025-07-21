//  https://neps.academy/br/course/estrategias-avancadas-de-programacao/lesson/segredo-do-cofre

#include <iostream> 
#include <bits/stdc++.h>

using namespace std;

/*
A ideia geral é simples. eu tenho uma lista com inteiros de 0 a 9:
Ai eu vou mover um contrtolhe partindo de uma posição e a gente tem que contar quantas vezes cada numero aparece
5 4
5 8 0 5 1
1 4 2 5

Eu poderia resolver com 2 fors, tipo
int main(){

    int N, M; cin >> N >> M;

    vector<int> lista(N);
    for (int i =0; i<N; i++){
        cin >> lista[i];
    }
    
    vector<int> posicoes(M);
    for (int i=0;i<M;i++){
        cin >> posicoes[i];
    }

    vector<int> Nvezes(10,0);
    Nvezes[lista[posicoes[0]-1]]++;//pos inicial 
    for (int i =0; i<M-1; i++){
        //eu vou de posicoes[i] até posicoes[i+1]
        // 5 4
        // 0 1 2 3 4
        // 5 8 0 5 1
        // 1 4 2 5
        // De 1 até 4 eu checo indices 1, 2, 3
        // de 2 até 5 eu checo 2, 3, 4
        // se posicoes[i] > posicoes[i+1] então é um for(int j = posicoes[i]; j <posicoes[i+1]; j++)

        // De 4 até 1 -> 2 1 0 isso é (for int j = posicoes[i+1]-1; j<posicoes[i]-1; j++)
        // De 1 até 4 -> 1, 2, 3
        //se posicão i for menor que posição i+1 então o loop é de  posicoes[i] até posição i+1
        //se nao (tipo de 4 até 1) ai é de posição[i+1]-1 até posição[i]-1 (de 0 até 3)
        bool x = posicoes[i]<posicoes[i+1];
        int a = x ? posicoes[i] : posicoes[i+1]-1;
        int b = x ? posicoes[i+1] : posicoes[i]-1;

        for (int j = a; j <b; j++){
            Nvezes[lista[j]]++;
        }
    }

    for (int x : Nvezes){
        cout << x << " ";
    }
    return 0;
}

Mas uma forma mais rápida seria armazenar um vetor pra cada soma

0 1 2 3 4
1 3 5 2 1
1 4 9 11 12

Soma [A até B] = Soma[B] - Soma[A-1]
*/

int main(){

    int N, M; cin >> N >> M;

    vector<int> lista(N);
    for (int i =0; i<N; i++){
        cin >> lista[i];
    }
    
    vector<int> posicoes(M);
    for (int i=0;i<M;i++){
        cin >> posicoes[i];
    }

    vector<vector<int>> PM;
    vector<int> Soma(10,0); 
    for (int i=0; i<N; i++){
        Soma[lista[i]]++;
        PM.push_back(Soma);
    }

    vector<int> Nvezes(10,0);
    Nvezes[lista[posicoes[0]-1]]++;

    for (int i = 0; i < M-1; i++){
        int pos1 = posicoes[i] - 1;// -1 pq o vetor cmc em 0
        int pos2 = posicoes[i+1] - 1;  
        
        int a, b;//de b até a
        
        if (pos1 < pos2) {
            //pra direita, pos1+1 até pos2
            a = pos1; 
            b = pos2;
        } else {
            //pra esquerda, pos2-1 até pos1-1
            a = pos2 - 1;
            b = pos1 - 1;
        }

        for (int j = 0; j < 10; j++) {
            Nvezes[j] += PM[b][j] - (a >= 0 ? PM[a][j] : 0);
        }
    }

    for (int x : Nvezes){
        cout << x << " ";
    }
    return 0;
}

