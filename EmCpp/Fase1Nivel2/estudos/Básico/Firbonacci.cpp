#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int fib(int n){
    if (n==1 || n==2){
        return 1;
    }

    return fib(n-1) + fib(n-2);
}

int main(){
    int A=0;
    cin >> A;

    cout << fib(A);

    return 0;
}

