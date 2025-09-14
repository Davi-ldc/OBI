//https://neps.academy/br/course/algoritmos-em-grafos/lesson/familias-de-troia

#include <iostream>
#include <bits/stdc++.h>
#define int long long

using namespace std;

/*
Ta, eu tenho um grafo tipo
1 2 grafo[1].push_back(2);
2 3
3 4
4 1
*/

int Nsecao = 0;
vector<bool> visitados;
vector<int> secao;
vector<vector<int>> grafo;

int N, M;

/*
A ideia é a partir de grafo[1] a gente
* marca que visitados[1] é verdadeiro (já que 1 já foi visitado)
* Visita todo mundo em grafo[1] ou seja todo mundo que pode ser alcançado a partir do 1 
* Isso é O(N+M) já que vc tem N pessoas gerando M conexões 
*/
void DFS(int v){
  // cout << "visitando: " << v << endl;
  visitados[v] = true;//1
  secao[v] = Nsecao;

  for (int cara : grafo[v]){
    //Se o cara não tiver sido visitado
    if (!visitados[cara]){
      DFS(cara);
    }
  }

}

main (){
  //Pessoas, conexoes
  cin >> N >> M;
  grafo.resize(N+5);//N vetores, um pra cada pessoa
  visitados.resize(N+5,false);//Gordurinha XD
  secao.resize(N+5);
  //Como é bidirecional
  for (int i=0; i<M; i++){
    int a,b; cin >> a >> b;
    grafo[a].push_back(b);//Da pra ir de a até b
    grafo[b].push_back(a);//e de b até a
  }
  //Joia, ai temos que fazer um bfs pra encontrar seções 
  for (int i =1; i<=N; i++){
    if (!visitados[i]){
      // cout<< "Rodei!" << i << visitados[i] << endl;
      DFS(i);
      Nsecao++;
    }
  }
  cout << Nsecao;


}
