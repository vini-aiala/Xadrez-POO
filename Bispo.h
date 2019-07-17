/*
* Descri��o geral da funcionalidade do m�dulo: Movimenta-se, verifica se o movimento � v�lido e desenha a pe�a no tabuleiro.
* Descri��o da interface do m�dulo: A pe�a do Bispo do xadrez.
* Data da ultima modifica��o:
*/
#ifndef pecaBispo
#define pecaBispo

#include <iostream>
#include <fstream>
#include "Peca.h"

class Bispo : public Peca
{
private:
protected:
public:
	Bispo(char simbolo);
	bool checaMovimento(int xAtual, int yAtual, int xDestino, int yDestino);
};
#endif 
