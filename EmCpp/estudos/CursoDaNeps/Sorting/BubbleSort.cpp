#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> V(N); 
    for(int i =0; i<N; i++){
        cin >> V[i];
    }

    for (int i =0; i<N;i++){
        bool sorteado = true;
        for(int j=0; j<N-1; j++){
            if(V[j]> V[j+1]){
                swap(V[j], V[j+1]);
                sorteado = false;
            }
        }
        if (sorteado){
            break;
        }
    }

    for (int x: V){
        cout << x << " ";
    }

    return 0;
}