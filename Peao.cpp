#include "Peao.h"

Peao::Peao(int simbolo)
{
	simboloPeca = simbolo;
	emJogo = true;
	jaMexeu = false;
	if (simbolo > 96)
		corPeca = true;
	else
		corPeca = false;
}

bool Peao::checaMovimento(int xAtual, int yAtual, int xDestino, int yDestino)
{
	if (yAtual - yDestino > 1 || yAtual - yDestino < -1) // verifica se o movimento eh valido ao ver que nao se mexe mais de 1 casa pelas colunas
		return false;
	if (!corPeca)
	{
		if (xAtual + 1 == xDestino) // verifica se o movimento eh valido ao ver que soh se mexe uma casas pelas linhas
		{
			jaMexeu = true; // indica que a peca ja se mexeu para nao poder andar 2 casas pelas linhas
			return true;
		}
		if (xAtual + 2 == xDestino && !jaMexeu && yAtual == yDestino) // verifica se o movimento eh valido ao ver que soh se mexe duas casas pelas linhas se ja nao se tiver se mexido
		{
			jaMexeu = true; // indica que a peca ja se mexeu para nao poder andar 2 casas pelas linhas
			return true;
		}
	}
	else
	{
		if (xAtual - 1 == xDestino) // verifica se o movimento eh valido ao ver que soh se mexe uma casas pelas linhas
		{
			jaMexeu = true; // indica que a peca ja se mexeu para nao poder andar 2 casas pelas linhas
			return true;
		}
		if (xAtual - 2 == xDestino && !jaMexeu && yAtual == yDestino) // verifica se o movimento eh valido ao ver que soh se mexe duas casas pelas linhas se ja nao se tiver se mexido
		{
			jaMexeu = true; // indica que a peca ja se mexeu para nao poder andar 2 casas pelas linhas
			return true;
		}
	}
	return false;
}
