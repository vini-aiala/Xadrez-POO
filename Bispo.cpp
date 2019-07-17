#include "Bispo.h"

Bispo::Bispo(char simbolo)
{
	simboloPeca = simbolo;
	emJogo = true;
	if (simbolo > 96)
		corPeca = true;
	else
		corPeca = false;
}

bool Bispo::checaMovimento(int xAtual, int yAtual, int xDestino, int yDestino)
{
	int x, y;
	x = xAtual - xDestino;
	y = yAtual - yDestino;
	bool flag = false;

	if (x == y || x == y * -1) // verifica se o movimento eh valido ao comparar a movimentacao em colunas e linhas para ver que a movimentacao foi feita diagonalmente
		flag = true;

	if(xAtual == xDestino) // verifica se o movimento eh invalido ao comparar que o destino eh igual a posicao atual
		flag = false;
	return flag;
}