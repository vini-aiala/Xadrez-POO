/*
* Descri��o geral da funcionalidade do m�dulo: Movimenta-se, verifica se o movimento � v�lido e desenha a pe�a no tabuleiro.
* Descri��o da interface do m�dulo: A pe�a do Pe�o do xadrez.
* Data da ultima modifica��o: 27 de Junho de 2019.
*/

#include <iostream>
#include <fstream>
#include "Peca.h"

class Peao : public Peca
{
private:
protected:
public:
	Peao(int simbolo);
	bool checaMovimento(int xAtual, int yAtual, int xDestino, int yDestino);
};