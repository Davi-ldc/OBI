N = int(input('N: '))

L = [] 

i=0
while i<N:
    L.append(int(input('energia: ')))
    i+=1

def dissonancia(L):
    size = len(L)
    d = 0 
    for c in range(size): 
        d += abs(L[c%(size)]-L[(c+1)%(size)])
        #a soma da diferença de vizinhos sendo primeiro com segundo
        #segundo com terceiro... até ultimo com prieiro
    return d


print(dissonancia(sorted(L)))
