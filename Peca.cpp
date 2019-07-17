#include "Peca.h"

char Peca::desenhaPeca()
{
	return simboloPeca;
}

bool Peca::getCor()
{
	return corPeca;
}

void Peca::comida()
{
	emJogo = false;
}

void Peca::mexida()
{
	jaMexeu = true;
}

bool Peca::getEmJogo()
{
	return emJogo;
}

bool Peca::getJaMexeu()
{
	return jaMexeu;
}
