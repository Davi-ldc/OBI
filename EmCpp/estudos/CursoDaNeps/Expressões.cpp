//https://neps.academy/br/course/fundamentos-das-estruturas-de-dados/lesson/expressoes

#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(){

    int n = 0;
    cin >> n;

    vector<string> v(n);
    for (int i=0;i<n;i++){
        cin >> v[i];
    }

    for (string str : v){
        bool valido = true;
        vector<char> pilha;
        for (char s : str){
            if(s == '(' || s == '[' || s == '{' ){//se for aberto adiciona ele ao topo
                pilha.push_back(s);
                continue;
            }
            else if (pilha.size()==0){ //se usar um )}] antes de abrir ta errado
                valido = false;
                break;
            }
            char topo = pilha[pilha.size()-1];
            if (s == ')' && topo == '(' ||//se s for fechado e o topo for aberto
                s == ']' && topo == '[' || 
                s == '}' && topo == '{'){
                    pilha.erase(pilha.begin()+pilha.size()-1); //tira eles 2 (no caso so o ultimo e nao adiciona o que fecha)
                }
            else {
                valido = false;
                break;
            }
        }

        if(valido && pilha.empty()){
            cout << "S" << endl;
        }
        else{
            cout << "N" << endl;
        }


    }
}