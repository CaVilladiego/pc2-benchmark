def main
	n = 50
	matriz = Array.new(n) {Array.new(n, 0)} # matriz[fila][columna]
	recorrer_matrix(matriz,1,0,0,n)
	
end

def recorrer_matrix(matriz, numActual, fila, columna, n)

	if numActual > n*n
		return
	end

	matriz[fila][columna] = numActual
	numActual = numActual + 1

	if fila == n - 1
		fila = columna + 1
		columna = n - 1
	else
		if columna == 0
			columna = fila + 1
			fila = 0
		else
			fila = fila + 1
			columna = columna - 1
		end
	end

	return recorrer_matrix(matriz, numActual,fila, columna, n)
end

main