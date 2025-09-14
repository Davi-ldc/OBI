#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
grafo onde grafo [i] tem um vetor com todos os elementos que ele ta conectado
pra cada elemento 

ta ai pra cada cara no grafo eu ando pela lista grafo[i] e marco
secao[grafo[i][j]] como 1 

ta mais o que passo como argumento pra DFS... Eu preciso saber qual vertice eu to olhando 
já que meio que ocorre a partir de algum lugar quem e já foi visitado;
então meio que eu só preciso de grafo[i][j] tipo

1 -> 2
1 -> 3 
2-> 4


5->6

gera um vetor
[ [2,3], [4], [], [] ]

ai tem que ter um i = vertice que eu to olhando

//finje que é 1-based 
dps de rodar DFS(1) i++; ai antes de rodar DFS(2) checa se visitados[2] = 1

DFS(1) chama DFS(2) e DFS(3) marca 1 como vistado; secao[1] = 1; ai DFS(2) marca 2 como visitado e 
adiciona secao[2] = 1


*/
int Nsecao = 0;
int N, M;//Vertices arestas

vector<int> visitados;
vector<int> secao;
vector<vector<int>> grafo;

void DFS(int v){
  //DFS 0 olha grafo [0];(check) marca secao[0] = Nsecao (check); marca visitados[0] = 1

  //Se já tiver sido visitado 
  if(visitados[v]){
    return;
  }

  secao[v] = Nsecao;
  visitados[v] = 1;
  for(int i=0; i<grafo[v].size(); i++){
    DFS(grafo[v][i]);
  }
}

int main(){

  cin >> N >> M;//N vertices M arestas
  grafo.resize(N+1);
  secao.resize(N+1,0);
  visitados.resize(N+1,0);

  for(int i =0; i < M; i++){
    int a, b; cin >> a >> b;
    grafo[a].push_back(b);
    grafo[b].push_back(a);
  }

  vector<pair<int,int>> respostas;
  for(int i =1; i <= N; i++){
    //Se ele já tiver sido visitado não precisa encrementar nem rodar dfs denovo 
    if (!visitados[i]){
      DFS(i);
      Nsecao++;

      //Se de 3-4 eu eu tenho uma seção nova; logo 3 e 4 nao tão conectados
      //logo eu deveria conectar 3 e 4 (aka i e i-1)

      if (i>1){
        respostas.push_back({grafo[i][0],grafo[i-1][0]});
      }
    }
  }
  cout << Nsecao-1 << endl;
  for (auto p : respostas){
    cout << p.first << " " << p.second;
  }

  return 0;
}