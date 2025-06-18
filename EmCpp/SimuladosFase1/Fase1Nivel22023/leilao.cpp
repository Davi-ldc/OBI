//https://neps.academy/br/exercise/2322

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int N; 
    cin >> N;

    vector<pair<int,string>> V;
    for (int i =0; i<N; i++){
        int tempi;
        string temps;
        cin >> temps >> tempi;
        V.push_back({tempi, temps});
    }

    stable_sort(V.begin(),V.end(),[](auto a, auto b){ return a.first > b.first;});

    cout << V[0].second << endl << V[0].first ;

    return 0;
}
