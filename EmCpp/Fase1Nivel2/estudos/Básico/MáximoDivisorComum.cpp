#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int mdc(int a,int b){
    if (b>a){
        swap(a,b);
    }
    if (a%b == 0){
        return b;
    }
    return mdc(b,a%b);
}

int main(){
    int A,B=0;

    cin >> A >> B;
    cout << mdc(A,B) << " é o mdc entre" << A << "," << B;
}