#include "Rei.h"

Rei::Rei(int simbolo)
{
	simboloPeca = simbolo;
	emJogo = true;
	if (simbolo > 96)
		corPeca = true;
	else
		corPeca = false;
}

bool  Rei::checaMovimento(int xAtual, int yAtual, int xDestino, int yDestino)
{
	if ((xAtual - xDestino < 2 && xAtual - xDestino > -2) && (yAtual - yDestino < 2 && yAtual - yDestino > -2) && !(xAtual == xDestino && yAtual == yDestino)) // verifica se o movimento eh valido ao ver que nao se mexe mais de 1 casa em cada direcao
		return true;
	return false;
}
