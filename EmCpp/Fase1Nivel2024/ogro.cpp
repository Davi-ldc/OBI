//https://neps.academy/br/exercise/2710
//esse era pra checar se o candidato tava vivo

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int E, D;
    cin >> E >> D; 

    int resposta;

    if (E>D){resposta = E + D;}
    else {resposta = 2*(D-E);}

    cout << resposta;

    return 0;
}
