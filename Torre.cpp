#include "Torre.h"

Torre::Torre(char simbolo)
{
	simboloPeca = simbolo;
	emJogo = true;
	if (simbolo > 96)
		corPeca = true;
	else
		corPeca = false;
}

bool Torre::checaMovimento(int xAtual, int yAtual, int xDestino, int yDestino)
{
	if (xAtual == xDestino && yAtual != yDestino || xAtual != xDestino && yAtual == yDestino) // verifica se o movimento eh valido ao ver que a coluna ou a linha nao muda
		return true;
	return false;
}
