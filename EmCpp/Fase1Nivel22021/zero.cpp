#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int N; cin >> N;
    vector<int> V;
    
    for(int i =0;i<N; i++){
        int temp; cin >> temp;
        if (!V.empty() && temp == 0){
            V.pop_back();
        }
        else{
            V.push_back(temp);
        }
    }

    int soma = 0;
    for(int x: V){
        soma += x;
    }
    cout << soma;

    return 0;
}