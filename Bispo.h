/*
* Descrição geral da funcionalidade do módulo: Movimenta-se, verifica se o movimento é válido e desenha a peça no tabuleiro.
* Descrição da interface do módulo: A peça do Bispo do xadrez.
* Data da ultima modificação:
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
