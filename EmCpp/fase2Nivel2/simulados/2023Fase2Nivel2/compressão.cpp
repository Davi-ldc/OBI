//https://neps.academy/br/exercise/2435
#include <iostream> 
#include <bits/stdc++.h> 
#define int long long 

using namespace std;

main() {
    int N; cin >> N;
    vector<char> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    map<char, int> Mapa;
    vector<char> ordem;
    for (char c : C) {
        if (Mapa.find(c) == Mapa.end()) {
            Mapa[c] = 1;
            ordem.push_back(c); 
        } else {
            Mapa[c]++;
        }
    }

    for (char c : ordem) {
        cout << Mapa[c] << " " << c << " ";
    }
}