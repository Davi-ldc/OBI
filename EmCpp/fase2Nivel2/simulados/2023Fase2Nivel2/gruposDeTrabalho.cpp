#include <iostream>
#include <bits/stdc++.h>
#define int long long 

using namespace std;

main (){
    //Estudantes Gostam NaoGostam
    int E, G, NG; cin >> E >> G >> NG;

    //Restrição 1 -> msm grupo
    vector<pair<int,int>> junto(G);    
    for (int i =0;i<G;i++){
        int a, b; 
        cin >> a >> b;
        junto[i] = {a,b};
    }

    //Restição 2 -> n msm grupo
    vector<pair<int,int>> njunto(NG);    
    for (int i =0;i<NG;i++){
        int a, b; 
        cin >> a >> b;
        njunto[i] = {a,b};
    }

    vector<vector<int>> EmQueGrupo(1e7); 
    //vector[posição] aponta pra um vetor com o trio onde esse cara ta
    for (int i =0; i<E; i+=3){
        int a,b,c; cin >> a >> b >> c;
        //Se tomar MLE v pode ser referencia
        vector<int> v = {a,b,c};
        EmQueGrupo[a] = v;
        EmQueGrupo[b] = v;
        EmQueGrupo[c] = v;
    }

    /*
    ta pra cada par são N * logN * 3 operações 
    como são 2 pares O(2*N*N*logN*3)
    */
    int resposta = 0;
    for (auto par : junto){
        //Par 1,2 logo em vec[1] 2 tem que existir, se não resposta++
        vector<int>& v = EmQueGrupo[par.first];//O(N)
        if (find(v.begin(), v.end(), par.second) == v.end()) {
            resposta++;
        }
    }

    for (auto par : njunto){
        // se map[par.first] nao estiver 
        vector<int>& v = EmQueGrupo[par.first];
        if (find(v.begin(), v.end(), par.second) != v.end()) {
            resposta++;
        }
    }

    cout << resposta;
    
}