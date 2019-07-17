#include "Posicao.h"

Posicao::Posicao(int in_linha, int in_coluna)
{
	coluna = in_coluna;
	linha = in_linha;
	peca = 0;
}

int Posicao::getColuna()
{
	return coluna;
}

int Posicao::getLinha()
{
	return linha;
}

char Posicao::desenhaPeca()
{
	if (peca)//verifica se o endereco da peca existe, caso nao retorna um caractere espaco
		return peca->desenhaPeca();
	else
		return ' ';
}

bool Posicao::getPecaCor()
{
	if(peca)//verifica se o endereco da peca existe
		return peca->getCor();
	return false;
}

Peca *Posicao::getPeca()
{
	return peca;
}

void Posicao::setPeca(Peca *pecaAux)
{
	peca = pecaAux;
}

bool Posicao::checaMovimento(int xAtual, int yAtual, int xDestino, int yDestino)
{
	if (peca)//verifica se o endereco da peca existe
		return peca->checaMovimento(xAtual, yAtual, xDestino, yDestino);
	else
		return 0;
}
