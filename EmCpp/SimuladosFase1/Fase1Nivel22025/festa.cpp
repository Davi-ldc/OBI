#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
    x       y   
A-------B-------C
A->B->C->A = x + y + x+y
B->C->A->B = y + x+y + x
C->B->A->C = y + x + x+y
De qual quer jeito é 2x + 2y

Isso por que saindo de um ponto A, para passar por outros 2 pontos B e C que estão a uma distancia
X e Y, você precisa andar X para chegar ao ponto A, Y para chegar ao ponto B. Só que quando
você anda X e Y para perto de B ou C, está obrigatóriamente se distanciando de A. Por isso todos
os caminhos tem uma distancia total de 2X+2Y
*/

int main(){

    int A, B, C;
    cin >> A >> B >> C;

    //X (A-B) + Y (B-C) + X+Y (A-C);
    //Isso por que sempre começamos em E, ou seja, a distancia total vai ser inevitavelmente
    //A distancia de E até S + E até L + S até L tipo no caso de 10 5 13
    //10->5 (5) 5-> 13 (8) 13->10 (3) = 16 é o mesmo que
    //10 -> 13 (3) 13->5 (8) 5-> 10 (5) = 16

    //independente da ordem, 1 deles é x, o outro é y e o outro é x+y
    // int distancia = abs(A - B) + abs(B - C) + abs(C - A);

    //Outra forma seria
    vector<int> V = {A,B,C};
    sort(V.begin(),V.end());

    int distancia = 2*(abs(V[1]-V[0])+abs(V[1]-V[2]));

    cout << distancia;
    return 0;
}