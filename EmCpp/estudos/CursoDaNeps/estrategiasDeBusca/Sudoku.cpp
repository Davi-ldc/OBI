#include <iostream>
#include <bits/stdc++.h>

using namespace std;


// Cada linha deve conter todos os números de 1 a 9, sem repetição.
// Cada coluna deve conter todos os números de 1 a 9, sem repetição.
// Cada subgrade 3x3 deve conter todos os números de 1 a 9, sem repetição.

/*
Vamosss lá, Vamos pensar do jeito burro primeiro. Imagina que agnt tem 17 numeros já prenchidos
e quer achar o proximo, como humano mesmo, poderiamos só ir testando e ver se o numero é valido

Mas pera, quando que ele é valido? Dado o indice i,j um número é valido se na linha não tiver nenhum numero
igual a ele ou seja pra cada elemento em M[i] nenhum pode ser igual ao numero desejado. Da até pra cmc com o set
{1,2,3,4,5,6,7,8,9} e ir iterando sobre M[i][X] tirando os valores k do set (o (log N)) E o mesmo para M[X][j]

Ta, mais ainda falta chechar o quadrante. Pensa neles como uma matriz:
M -> 
{
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
}
repara que é so pegar a posição i/3 e j/3 nessa matrix pra achar o quadrante

tipo: (é o mesmo na vertical)
0 0 0 1 1 1 2 2 2 index
0 1 2 3 4 5 6 7 8 posição; Ta já sabemos checar se um numero é valido.

Pra cada iteração eu poderia pegar meu set com os numeros possiveis, e ver ir deletando os que aparecem
na linha; na coluna; no quadrante. e se não tiver nenhum faz o backtrack 


*/


bool isval(vector<vector<int>>& M, int i, int j, int v){
    
    //linha
    for (int k =0; k < M.size(); k++){
        if(M[i][k] == v){
            return false;
        }
    }
    //coluna
    for (int k =0; k < M.size(); k++){
        if(M[k][j] == v){
            return false;
        }
    }

    int cmci = (i/3)*3;
    int cmcj = (j/3)*3;
    for (int k =cmci; k<cmci+3; k++){
        for (int l=cmcj; l<cmcj+3; l++){
            if(M[k][l] == v){
                return false;
            }
        }
    }

    return true;
    
}

// vector<int> n = {1,2,3,4,5,6,7,8,9};

bool solveSDK(vector<vector<int>>& M){

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){//percore todas as celulas
            if (M[i][j] == 0){//se tiver vazia 

                for(int k=0; k<9; k++){ //Tenta todos os numeros de 1 a 9
                    if (isval(M,i,j,k+1)){ //se um deles for valido

                        M[i][j] = k+1;//tenta resolver com esse numero a partir da qui

                        if (solveSDK(M)){
                            return true; 
                        }
                        else{//se não desfaz a jogada e tenta outro numero
                            M[i][j] = 0;
                        }

                    }
                }

                //Se testar todos os numeros possiveis sem sucesso retorna false
                return false;
            }
        }
    }
    return true; //Quando tudo tiver preenchido, vai chegar aqui 
}

int main(){

    vector<vector<int>> M(9, vector<int>(9,0));//inicia as 9 colunas

    for (int i =0; i<9; i++){// pra cada linha
        for (int j = 0; j<9; j++){// le 9 numeros
            cin >> M[i][j];
       }
    }

    bool valido = true;
    for (int i = 0; i < 9 && valido; i++) {
        for (int j = 0; j < 9 && valido; j++) {//pra toda celula
            if (M[i][j] != 0) {//se a celula tiver preenchida
                int temp = M[i][j];
                M[i][j] = 0;
                if (!isval(M, i, j, temp)) {
                    valido = false;
                }
                M[i][j] = temp;
            }
        }
    }

    if (!valido){
        cout << "NO SOLUTION";
    }
    else {
        solveSDK(M);
        for (auto x : M){
            for (int i : x){
                cout << i << " ";
            }
            cout << endl;
        }
    }



    return 0;
}