#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main (){

    string s = "";
    cin >> s;

    int size = s.size();

    string v = "";
    string c = "";

    string vogais = "aeiou";

    for(int i=0; i<size; i++){
        if (vogais.find(s[i]) != string::npos){
            v += s[i];
        }
        else {
            c += s[i];
        }
    }

    cout << "Vogais: " << v << endl;
    cout << "Consoantes: " << c << endl;

    
    return 0;
}