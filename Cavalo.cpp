#include "Cavalo.h"

Cavalo::Cavalo(int simbolo)
{
	simboloPeca = simbolo;
	emJogo = true;
	if (simbolo > 96)
		corPeca = true;
	else
		corPeca = false;
}

bool Cavalo::checaMovimento(int xAtual, int yAtual, int xDestino, int yDestino)
{
	if (yAtual + 2 == yDestino && xAtual + 1 == xDestino || yAtual + 2 == yDestino && xAtual - 1 == xDestino || yAtual + 1 == yDestino && xAtual + 2 == xDestino || yAtual - 1 == yDestino && xAtual + 2 == xDestino || yAtual - 2 == yDestino && xAtual + 1 == xDestino || yAtual - 2 == yDestino && xAtual - 1 == xDestino || yAtual + 1 == yDestino && xAtual - 2 == xDestino || yAtual - 1 == yDestino && xAtual - 2 == xDestino) // verifica se o movimento eh valido ao somar a movimentacao vertical e horizontal permitido para a peca
		return true;
	return false;
}
