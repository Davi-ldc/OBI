//https://neps.academy/br/exercise/241

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main (){
    int n = 0;
    cin >> n;

    int arr[n];//array com n posições
    for (int i=0; i < n; i++){
        cin >> arr[i];
    }

    for (int c = 0; c < n; c++){
        if (n == 1){
            cout << arr[0];
            break;
        }
        else if (c == 0){
            cout << arr[c] + arr[c+1] << "\n";
        }
        else if (c == n-1){
            cout << arr[c] + arr[c-1] << "\n";
        }
        else{
            cout << arr[c] + arr[c+1] + arr[c-1] << "\n";
        }
    }
    
    

    return 0;
}