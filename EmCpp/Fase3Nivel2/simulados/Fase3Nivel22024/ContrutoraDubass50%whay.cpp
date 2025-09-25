//https://neps.academy/br/exercise/2929
#include <iostream>
#include <bits/stdc++.h>
#define int long long 

using namespace std;

main (){

  int N; cin >> N;

  vector<int> V(N);
  int min = INT_MAX;
  for(int i=0; i<N; i++){
    int temp; cin >> temp;
    V[i] = temp;
    if (temp < min){
      min = temp;
    }
  }

  /*
  é bem simples, temos que achar a maior sequência de números iguais, atualizar o vetor, repetir 
  */  

  int resposta = 0;
  while (true){
    int i =0;
    pair<int,int> i_j = {0,0};
    int n = V[0];

    // cout << min << endl;
    //3 2 2 1
    //j=1 j<3 j =2?
    for (int j =1; j<N; j++){
      /*
      exemplo: 0,0 lengh é 0-0+1  (já que o ultimo é incluido)
      caso da sequencia continuar
      */
      //V[2] = 1 == min && 2 = n
      if(V[j] == min && V[j] == n && j-i+1 >= i_j.second - i_j.first + 1){
        i_j.first = i;
        i_j.second = j;
      }
      else {//caso de não continuar tipo 5 4 4 4 5
        i = j;//quando j chegar no ultimo 5 i vai pra lá tmb
        n = V[j];
        if (V[j] == min && j == N-1 ) {
          i_j.first = i;
          i_j.second = j;
        }
      }
    }
    
    // cout << i_j.first << " " << i_j.second << endl;
    if(i_j.first == 0 && i_j.second == V.size()-1){
      break;
    }
  
    // dps só atualizar:
    for (int i = i_j.first; i<=i_j.second; i++){
      V[i]++;
    }
    resposta++;
    if (find(V.begin(), V.end(), min) == V.end()){
      min++;
    }
    
    for(int x: V){
      cout << x << " ";
    }

    // cout << endl;
  }

  cout << resposta;
}
