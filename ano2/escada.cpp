#include <iostream>
#include <vector>
#define int long long

using namespace std;

//Numa escada com N degraus vc pode subir 1 ou 2 por vez. De quantas formas diferentes da para chegar ao topo?

/*
com 1 degrau -> 1; 
2-> 1,1 2
ai, a partir do terceiro. Ou ele veio de -1 ou de -2 
*/


signed main (){

    int N; cin >> N; 
    if (N == 1) {cout << 1; return 0;}
    if (N == 2) {cout << 2; return 0;}

    vector<int> dp(N+1);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i<=N; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout << dp[N];

    return 0;
}

//Versão otimizada:
/*

signed main (){

    int N; cin >> N; 
    if (N == 1) {cout << 1; return 0;}
    if (N == 2) {cout << 2; return 0;}

    int a = 1;
    int b = 2;

    for (int i = 3; i<=N; i++){
        if (i%2==1){
            a += b;
            continue;
        }
        b += a;
    }

    if (N%2==1){
        cout << a;
        return 0;
    }
    cout << b;

    return 0;
}
*/