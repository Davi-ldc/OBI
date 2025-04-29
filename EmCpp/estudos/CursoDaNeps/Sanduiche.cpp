#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
Ta, agente tem que contar quantos pares (i,j) onde 1<=i<=j<=N existem
tais que o somatório C[i] + C[i+1]... C[j] seja igual a D 

Como sempre vamo analisar uma entrada:

5 10 //numero de pedaços e a quantidade que vc quer comer
1 2 3 4 3 //tamanho dos pedaços
0 1 2 3 4 //index

Ta, no exemplo acima tem 5 pedaços, e eu quero comer 10cm de sanduiche
mas eu não posso pegar de forma aleatória. Tem que ser ou das estremidades
ou uma sequencia. Nesse caso, da pra pegar os 4 primeiros pedaços
Já que 1+2+3+4 = 10, pegar os ultimos 3 (3+3+4), ou pegar das extremidades (1+2 + 4+3);
Tá acho que entendi melhor o que ele quer e a ideia de extremidades, tipo assim
pegar das extremidades é tipo excluir o meio. Pegar os pedaços 1,2  4,3 é excluir o 3 do meio
da pra represenatar isso como pegar do 0 até 1 e depois do 4 até o 3. Ou 
de 0 até i, de j até o final

5 5
1 1 1 1 1
0 1 2 3 4

Ta, aqui eu quero comer 5 centimetros, é massa pensar que pra cada ação ele pode comer o 
seguinte ou pegar da extremidade, então vamo dividir em 2 grupos. 
Só sequencia-> Só tem como ser do elemento 0 até o 4
Usando as extremidades-> Poderia pegar 3 vezes da extremidade exquerda e 2 vezes da extremidade direita
ou 2 vezes da esquerda e 3 da direira //mas como o index tem que ser i,j onde i é menor essa opção ta fora
Poderia pegar 5 da extremidade esquerda e 0 da direita;
4 da extremidade esquerda e 1 da direita (4,1)
3 da extremidade esquerda e 2 da direita (3,2)
2 da extremidade esquerda e 3 da direita (2,3)
1 da extremidade esquerda e 4 da direita (1,4)
0 da extremidade esquerda e 5 da direita (0,5)

Masss ele quer o par i j onde i é menor ou igual a j então as opções são
Pegar a sequencia (0,4) e as extremidades (0,4), (1,3), (2,2)
dai pra frente já é j>i então ta fora (já que AB e BA é a mesma coisa)

Ta, mas como eu vou checar isso... Só o caso da sequencia 
1 1 1 1 1//valor
0 1 2 3 4//index
tem 5² sequencias possiveis se você pensar em i,j i pode ser de 0 a 4 e j tmb então 5x5 possibilidades
Eu poderia testar todas elas e ver se alguma soma D mas ai é O(N²) e como N pode ser até 10^6 o ideal é
log n, n log n ou até O(N)

A questão aqui é, dado uma lista de inteiros de quantas formas eu posso somar 10 com caras consecutivos?
Até quando é so das bordas, ainda são elementos consecutivos. Maibe de pra usar uma recursão tipo ver quanto soma
os caras 0-1 2-3 4-5... meh, não funciona por que se fosse 0 2 não ia pegar.

Maibe um map com valor, index deixaria eles ordenados por valor... meh não sei como ajudaria a encontrar
os que somam D.

Analizando outra entrada:
9 618 //N,D
665 658 248 282 428 562 741 290 457
Maibe pra olhar a sequencia da pra checar 0, 0+1 e se for > D então já começa a partir de index onde parou +1 
se for == D então resposta++ e também continua de D+1. repara que isso é O(N) #CHECK

Mas ainda falta as extremidades, pensa em como um humano faria, naquele caso tipo

5 10//N, D
1 2 3 4 3

Eu ia ver a soma de um lado e ir comparando com a do outro mas fica em N² se eu olhar tipo
primeiro + ultimo
primeiro + segundo +ultimo
primeiro + segundo + terceiro + ultimo ai quando terminasse ainda teria que ver
primeir + segundo + penultimo + ultimo... Que horor. Talvez de pra ir comparando de outra forma

Da até pra imendar com o calculo das sequencia, pensa comigo, se primeiro + segundo = x 
então falta D-x pra pra chegar a D... Acho que essa é a ideia principal ir percorendo o array da 
esquerda pra direita checando as sequencias e ao mesmo tempo tipo olhou o primeiro, olha o ultimo
olhou o primeiro + segundo se isso for > D então não precisa olhar... Alguma coisa assim, acho que fica em 
O(N)
*/

int main(){

}