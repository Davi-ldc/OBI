//https://neps.academy/br/exercise/976

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main () {
    int A, N;
    cin >> A >> N;

    cout << (A/(N+2))*2 << endl;
    //A = NX + 2X
    //A = X(N+2)
    //X = A/N+2
    //2x = (A/(N+2))*2 
    return 0;
}