//https://neps.academy/br/exercise/2434
#include <iostream> 
#include <bits/stdc++.h> 
#define int long long 

using namespace std;

main (){
    //Numero de pessoas, pizza de 8 pedaços, pizza de 6 pedaços
    int N, G, M; cin >> N >> G >> M;

    int P = G*8 + 6*M;
    if(P-N>=0){
        cout << P-N;
    }
    else{
        cout << 0;
    }
}