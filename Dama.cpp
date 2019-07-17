#include "Dama.h"

Dama::Dama(int simbolo)
{
	simboloPeca = simbolo;
	emJogo = true;
	if (simbolo > 96)
		corPeca = true;
	else
		corPeca = false;
}

bool Dama::checaMovimento(int xAtual, int yAtual, int xDestino, int yDestino)
{
	int x, y;
	x = xAtual - xDestino;
	y = yAtual - yDestino;
	if (xAtual == xDestino && yAtual == yDestino) // verifica se o movimento eh invalido ao ver que a coluna e linha nao muda, ou seja, a peca nao se mexeu
		return false;
	if (x == y || x == y * -1) // verifica se o movimento eh valido ao comparar a movimentacao em colunas e linhas para ver que a movimentacao foi feita diagonalmente
		return true;
	if (xAtual == xDestino || yAtual == yDestino) // verifica se o movimento eh valido ao ver que a coluna ou a linha nao muda
		return true;
	return false;
}
