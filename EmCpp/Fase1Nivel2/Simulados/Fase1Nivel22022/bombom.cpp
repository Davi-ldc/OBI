#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
As -> 10
V->11
D->12
R->13
*/

int main(){

    map<char,int> valores = {{'A', 10}, {'J', 11}, {'Q', 12}, {'K', 13}};

    string P; cin >> P;
    char NDominante = P[1];

    int p1 = 0;
    int p2 = 0;

    for(int i=0;i<3;i++){
        string temp; cin >> temp;
        if(temp[1] == NDominante){
            p1+=4;
        }
        p1 += valores[temp[0]];
    }
        for(int i=0;i<3;i++){
        string temp; cin >> temp;
        if(temp[1] == NDominante){
            p2+=4;
        }
        p2 += valores[temp[0]];
    }
    
    if (p1>p2){
        cout << "Luana";
    }
    else if (p1<p2){
        cout << "Edu";
    }
    else if (p1==p2){
        cout << "empate";
    }
    return 0;
}