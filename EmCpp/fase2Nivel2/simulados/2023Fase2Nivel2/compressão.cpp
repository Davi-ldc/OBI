//https://neps.academy/br/exercise/2435
#include <iostream> 
#include <bits/stdc++.h> 
#define int long long 

using namespace std;

main() {
    int N; cin>>N;

    char anterior; cin >> anterior;
    int x = 1;
    if (N==1){
        cout << x << " " << anterior << " ";
    }
    for (int i=1; i<N; i++){
        char c; cin >> c;
        if (c==anterior){
            x+=1;
        }
        if (c!=anterior){
            cout << x << " " << anterior << " ";
            x = 1;
            anterior = c;
        }
        if (i == N-1){
            cout << x << " " << c << " ";
        }
    }
}
