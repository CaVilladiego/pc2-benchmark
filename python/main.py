import sys
sys.setrecursionlimit(10**6)


def main():
	N = 50
	matriz = [[0 for y in range(N)] for x in range(N)] #matriz[fila][columna]
	recorrer_matrix(matriz, 1, 0, 0, N)

	
	

def recorrer_matrix(matriz, numActual, fila, columna, N):

	if numActual > N*N:
		return

	matriz[fila][columna] = numActual
	numActual += 1

	if fila == N-1:
		fila = columna + 1
		columna = N-1
	elif columna == 0:
		columna = fila + 1
		fila = 0
	else:
		fila += 1
		columna -= 1

	return recorrer_matrix(matriz, numActual,fila, columna, N)




if __name__ == "__main__":
	main()