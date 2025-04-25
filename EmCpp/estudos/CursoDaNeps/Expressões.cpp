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
        bool valido = false;
        vector<char> pilha(str.size());
        for (char s : str){
            if(s == '(' || s == '[' || s == '{' ){
                pilha.push_back(s);
            }
            else if (pilha.size()==0){ //se usar um )}] antes de abrir ta errado
                valido = false;
                break;
            }
            char topo = pilha[pilha.size()-1];
            if (s == '(' && topo == ')' ||
                s == '[' && topo == ']' || 
                s == '{' && topo == '}'){
                    pilha.erase(pilha.begin()+pilha.size()-1); 
                }
            else {
                valido = false;
                break;
            }
        if(valido && !pilha.empty()){
            cout << "S";
        }
        else{
            cout << "N";
        }
    }
    }
}