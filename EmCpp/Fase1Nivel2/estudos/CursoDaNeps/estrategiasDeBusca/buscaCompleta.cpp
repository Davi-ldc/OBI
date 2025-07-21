#include <iostream> 
#include <bits/stdc++.h> 

using namespace std;

void imprimirTds(int i, vector<int>& v, vector<int>& currentV){
    //a logica é pra cada um deles agente pode imprimir ou n

    if (i == v.size()){
        for (int c : currentV){
            cout << c << " ";
        }
        cout << endl;
        return;
    }

    imprimirTds(i+1, v, currentV);//não inclue

    currentV.push_back(v[i]);
    imprimirTds(i+1,v,currentV);

    currentV.pop_back();
}

int main(){


    int i =0;
    vector<int> sla = {1, 2, 3};
    vector<int> vaziu;
    imprimirTds(i,sla,vaziu);
    return 0;
}