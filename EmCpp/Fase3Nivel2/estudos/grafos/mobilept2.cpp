#include <iostream>
#include <bits/stdc++.h>
#define int long long

using namespace std;

int N;
int Nsecao;
int rodando = 1;

vector<vector<int>> grafo;

/*
1 0
2 1
3 1
*/

//Cada cara precisa olhar as pessoas em baixo dele e ver se o peso delas é o mesmo
int dfs(int v, int profundidade){

  int peso = 1;//A propria peça pesa 1
  vector<int> pesos;

  for (int cara : grafo[v]){
    int p = dfs(cara, profundidade+1);//Peso do cara
    pesos.push_back(p);//Adiciona a lista

    peso += p;//e os dos de baixo
  }

  if (pesos.size() != 0 ){
    for (int i=0; i<pesos.size()-1; i++){
      //O peso de todo mundo tem que ser igual
      if (pesos[i] != pesos[i+1]){
        //Se algum dos pesos for difente o grafo ta desbalanceado logo
        rodando = 0;
        break;
      }
    }
  }

  //Depois de rodar esse for eu poderia checar se esse peso_profundidade é igual o dos
  //vizinhos
  return peso;

}

main(){
  cin >> N;
  grafo.resize(N+5);//Gordurinha XD

  for (int i =0; i<N; i++){
    int a, b; cin >> a >> b;
    //a esta ligado em b
    grafo[b].push_back(a);
  }

  for (auto v: grafo){
    for (int i : v ){
      cout << i << " ";
    }
    cout << endl;
  }

  dfs(0,0);

  if(rodando){
    cout << "bem";
  }
  else {
    cout << "mal";
  }
}