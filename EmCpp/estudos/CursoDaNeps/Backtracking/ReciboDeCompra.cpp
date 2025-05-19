#include <iostream> 
#include <bits/stdc++.h>

using namespace std;

/*
Ta, agente sabe quer saber quantas possibilidades de K elementos positivos somam R
Repara que, dado a soma de elemntos = s, agente precisa testar numeros até 
soma desejada - (soma atual +elementos que faltam add)

Repara tmb, que não da pra repetir elementos.

Mas essa tatica não é muito eficiente, testar todos os numeros, e checar quantas possibilidades tem

Vamo pensar em N = 12 e K = 3
ele testa 
{1 2 3}
{1 2 4}
{1 2 5}
{1 2 6}
{1 2 7}
{1 2 8}
até chegar a 1 2 9, quando a soma é 12. Mas repara que ao invez de fazer essa burice de testar tudo, quando tiver
no ultimo elemento, tipo agente sabe que K é 3, o V atual tem size = 3 e soma = x
o ultimo numero é obtido por -> Soma atual + Numero = R; Numero = R-Soma Atual
*/

int fac(int x){
    if(x==1 || x == 0){
        return 1;
    }
    return x*fac(x-1);
}

int sum(vector<int>& V){
    int t = 0;
    for (int x : V){
        t+=x;
    }
    return t;
}

int possibilidades(int& SomaDesejada, int& K, vector<int>& V){
    int SomaAtual = sum(V);

    cout << endl;
    cout << "{";
    for ( int c : V){
        cout << c << " ";
    }
    cout << "}";

    //caso base
    if (V.size()==K){//se o tamanho for igual a K
        if(SomaAtual==SomaDesejada){//se a soma for igual a R
            cout << "MAIS UM";
            return 1;
        }
    }

    //Ai pra cada posição no vetor de K elementos a gnt intera
    int i = 1 + V.size();
    int resposta=0;

    while(i < SomaDesejada/2){
        int anterior = V.empty() ? 0 : V[V.size()-1];
        //se o elemento não estiver no vetor
        if(find(V.begin(),V.end(),i) == V.end()){

            if(V.size() == K - 1){//se for o ultimo elemento
                int numero = SomaDesejada - SomaAtual;

                if (find(V.begin(),V.end(),numero) == V.end() && anterior<numero){
                    V.push_back(numero);
                    resposta += possibilidades(SomaDesejada, K, V);
                    V.pop_back();
                    break;
                }

            }
            else if (anterior<i){
                
                V.push_back(i);//adiciona o numero e testa a partir da i
                resposta += possibilidades(SomaDesejada, K, V);
                V.pop_back();
            }
        }
        i++;
    }

    return resposta;
}

int main(){

    int R, K;

    cin >> R >> K; 

    vector<int> V;
    //Repara que {1,5,6}, {1,6,5}, {5,6,1}... são equivalentes 
    //Ou seja, tem K fatorial jeitos de escrever a mesma 
    //e teria que dividir pra K! se a gente fizesse testando tds as possibilidades
    cout << possibilidades(R, K, V);

    return 0;
}
