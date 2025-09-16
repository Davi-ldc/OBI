#include <iostream>
#include <bits/stdc++.h>
#define int long long

using namespace std;

int N;
int Nsecao;
int resposta = 1;
int pesoGlobal;

vector<vector<int>> grafo;
// vector<int> visitados; não precisa já que só tem como ir pra baixo
vector<pair<int,int>> peso_profundidade;

void dfs(int v, int p){
  cout << "visitando " << v << " profundidade " << p << endl; 
  int peso = 0;
  /*
  Marca como visitado, checa as pessoas em baixo
  */
  for (int cara : grafo[v]){
    dfs(cara,p+1);
    peso++;
  }
  //Depois de rodar esse for eu poderia checar se esse peso_profundidade é igual o dos
  //vizinhos
  peso_profundidade[v] = {peso, p};

}

main(){
  cin >> N;
  grafo.resize(N+5);//Gordurinha XD
  peso_profundidade.resize(N+1, {-1,-1});

  for (int i =0; i<N; i++){
    int a, b; cin >> a >> b;
    //a esta ligado em b
    grafo[b].push_back(a);
  }

  dfs(0,0);

  for (auto par : peso_profundidade){
    cout << "peso " << par.first << " profundidade " << par.second << endl;
  }

  sort(peso_profundidade.begin(),peso_profundidade.end(), [](auto& a, auto& b{
    return a.second < b.second;//Se a menor que b; a vai na frente 
  }))


  /*
  Ta agora é só checar se todo mundo com uma profundidade p tem o mesmo peso
  */


}