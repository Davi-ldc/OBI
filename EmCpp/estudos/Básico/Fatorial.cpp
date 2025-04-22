#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int fac(int x){
    if (x == 0 || x == 1){
        return 1;
    }
    return x * fac(x-1);
}

int main(){
    int A;
    cin >> A;
    cout << fac(A);
}