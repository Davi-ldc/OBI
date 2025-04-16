import sys

entrada = sys.stdin.read().split("\n")[:3]
N = int(entrada[0][0]) # Numeros de pessoas (tamanho de B e G) Da até pra usar no lugar de len pra economizar
K = int(entrada[0][2]) # Numero de amigos
T = int(entrada[0][4]) #trocas permitidas

B = [int(x) for x in entrada[1].split(' ')] #EX: [4, 8, 1, 5, 7]
G = [int(x) for x in entrada[2].split(' ')] #EX: [1, 0, 1, 0, 0]


B = [(i, o) for i,o in sorted(enumerate(B), key=lambda x: x[1], reverse=True)] #EX:[(1, 8), (4, 7), (3, 5), (0, 4), (2, 1)]
#index, valor ordenado. só o enumerate ia ser (0,valor1), (1, valor2) ai 
#agente da um um sort com base no segundo valor do tuple

#Pre computando pra cada amigo a distancia pro prato mais vantajoso
#primeiro eu acho onde eles estão
def acharIndices(G):
    indices = []
    for c in range(len(G)):
        if G[c] == 1:
            indices.append(c)
    return indices

#ai pra cada um deles
distancias = [[] for _ in range(K)] #uma lista com listas pra cada _ em K

indices = acharIndices(G)
for c in range(len(indices)):
    for i in range(len(B)):
        #Eu monto uma lista com a distancia pra cada prato
        distancias[c].append(abs(B[i][0]-indices[c]))

print(distancias)




def MaisProximo(index):
    """
    Agente quer saber o cara em G mais proximo de algum indice qualquer que é == 1
    tipo se G =  [1, 0, 1, 0, 0] e B = [(1, 8), (4, 7), (3, 5), (0, 4), (2, 1)]
    Pra chegar nele é só pensar que o 8 tinha como index original 1 então agente olha 
    index original + 1, e index original 0-1 e repete até achar (se tiver mais pra direita)
    """
    i = index
    d = 1
    while True:
        if B[i][0]+d <= len(G)-1:
            if G[B[i][0]+d] == 1:
                return B[i][0]+d
        if 0 >= G[B[i][0]-d]:
            print(G[B[i][0]-d])
            if G[B[i][0]-d] == 1:
                return B[i][0]-d
        d += 1


# for c in range(len(B)):
#     if G[B[c][0]] == 1:
#         continue #caso já tenha alguem lá
#     #acha o amigo mais proximo ve quanto custa mover ele pra la 
#     #se valer apena move 
#     else:
#         #print(MaisProximo(B[c][0]))
#         pass

# print(entrada, B , G)


"""
Get-Content "Fase 3 nivel 2\entrada.txt" | python -u "Fase 3 nivel 2\Brigadeiros.py"


"""