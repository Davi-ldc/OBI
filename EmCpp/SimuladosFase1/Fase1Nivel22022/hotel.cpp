#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    //preço no dia 1, aumento a partir do dia 2, dia em que chegou
    //N menor ou igual a 31
    int D, A, N; cin >> D >> A >> N;

    int limite = N>15 ? 15 : N;
    int diaria = D + (A*(limite-1));

    cout << diaria * (32-N);
    return 0;
}