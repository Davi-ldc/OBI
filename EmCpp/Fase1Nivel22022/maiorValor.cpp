#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M, Sd; cin >> N >> M >> Sd;
    
    int valor = -1;

    for(int i=N; i<M+1; i++){
        vector<int> temp;
        int t = i;
        while (t>0){
            temp.push_back(t%10);
            t /= 10;
        }
        reverse(temp.begin(),temp.end());

        int s = 0;
        for (int x : temp){
            s+=x;
        }
        if(s == Sd){
            valor = i;
        }

    }
    cout << valor;

}