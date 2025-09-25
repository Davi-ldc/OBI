// https://neps.academy/br/exercise/2931

#include <iostream>
#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> p;
vector<vector<int>> grafo;
int N;

void add(int cara, int v){
  //Pra cada elemento em grafo[7], grafo[8] (caso eles tenham mais de um elemento)
  // cout << "visitando " << cara << endl;
  if(grafo[cara].size()>0){
    for (int c : grafo[cara]){
      grafo[v].push_back(c);//Eu vou adicionar eles ao grafo[5]
      p[c] = v;//atualiza a lista de subordinação
      // cout << "To chamando da qui " << endl;
      add(c,v);//e checar os filhos deles
    }
  }
  //depois que eu fizer isso posso limpar grafo[7], grafo[8]
  // cout << "TO LIMPANDO " << cara << endl;
  grafo[cara].clear();

}

void reestruturar(int v){

  for (int i=0; i<grafo[v].size(); i++){
    int cara = grafo[v][i];
    //Joia, eu sei que de 5 eu posso ir pro 7 e pro 8; Ai vou adicionar todo mundo 
    //em baixo deles, isso é grafo[7], grafo[8]
    // cout << "chegue " << cara << endl;
    add(cara,v);
    // cout << cara << " ";
  }

  // for (auto v : grafo){
  //   for (int cara : v){
  //     cout << cara << " ";
  //   }
  //   cout  << endl;
  // }

}

main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);


  cin >> N;
  grafo.resize(N+5);//gordurinha XD
  p.resize(N+5);
  p[0]=1;
  p[1]=1;

  for (int i = 2; i<=N; i++){
    int a; cin >> a;
    p[i] = a;
    //Se p[2] = 1 logo de 1 você consegue ir para o 2
    grafo[a].push_back(i);
  }


  //debug
  // for (auto v : grafo){
  //   for (int cara : v){
  //     cout << cara << " ";
  //   }
  //   cout  << endl;
  // }

  int Q; cin >> Q;

  vector<int> respostas;
  for (int i=0; i<Q; i++){
    int a; cin >> a;

    if(a==1){
      int nobre, k; cin >> nobre >> k;
      //Nobre nobre precisa entregar um relatório para alguem que está a k niveis acima
      int temp = p[nobre];//p[nobre] é a pessoa que ele precisa entregar
      for(int i =1; i<k; i++){
        temp = p[temp];//qnt de niveis acima
      }
      respostas.push_back(temp);
    }
    else {
      int b; cin >> b;
      reestruturar(b);
    }
  }

  for (int r : respostas){
    cout << r << endl;
  }

  //
}