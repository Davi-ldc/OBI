#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
Ta, eu tenho N objetos de tipo T e valor V 
ai C clientes vao vizitar a barraca tal que 

Se ele for decidido, compra um objeto do tipo T com o menor preço, se não tiver o tipo que ele quer nao compra nada
Se for indeciso compra o que tem o menor preço com um o menor tipo, se nao tiver nada nao compra nada

ai a gente que o valor total vendido... A questão é como armazenar os pares T V 
//8 objetos, 10 tipos enumerados de 1 a T
8 10 
//Tipos dos N objetos
4 2 3 1 10 1 1 4
//preços dos N objetos
43 50 156 81 97 12 3 3
//numero de clientes que visitaram a barrac (C)
7
//Se for 0 o cliente é indeciso, se não é o tipo do coiso que ele deseja
0 1 0 1 5 4
*/
int main (){

    //Quantidade de objetos
    long long O, T; cin >> O >> T;
    
    vector<int> tipos(O);
    for (int i=0; i<O; i++){
        cin >> tipos[i];
    }
    vector<int> preco(O);
    for (int i=0; i<O; i++){
        cin >> preco[i];
    }

    long long C; cin >> C;
    vector<int> clientes(C);
    for (int i =0; i<C; i++){
        cin >> clientes[i];
    }

    int resposta =0;
    for (int tipo:clientes){
        if (tipo == 0){
            resposta +=
        }
    }




    return 0;
}