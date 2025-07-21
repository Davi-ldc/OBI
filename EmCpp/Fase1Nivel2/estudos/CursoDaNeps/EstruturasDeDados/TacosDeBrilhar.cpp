//https://neps.academy/br/course/fundamentos-das-estruturas-de-dados/lesson/tacos-de-bilhar

#include <iostream>
#include <bits/stdc++.h> 

using namespace std;


/*
Só pelo: 
"ele nunca tem no estoque mais do que um taco com um determinado comprimento" já é set ou map

a ideia aqui é bem simples, só ir dando insert nos elementos, se o elemento não estiver lá, respota +=2
se tiver remove o cara do set

usando um set fica tudo em N log n, já que find é log n e insert tmb e eles tão dentro de um for;
daria pra fazer por vetor tmb mas fica em O(N²), usa upper bound pra achar se um elemento existe (OlogN)
e depois usa insert O(N) como ta dentro de um for -> O(N²); OBS-> erase tmb é O(N) no vetor

*/


int main(){

    int C;//numero de consultas
    cin >> C;

    set<int> estoque;
    int resposta = 0;
    for (int i=0; i<C; i++){
        int temp;
        cin >> temp;
        if(estoque.find(temp)==estoque.end()){//se for um elemento novo
            estoque.insert(temp);
            resposta += 2;
        }
        else{
            estoque.erase(temp);
        }
    }

    cout << resposta;

    return 0;
}