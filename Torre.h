/*
* Descrição geral da funcionalidade do módulo: Movimenta-se, verifica se o movimento é válido e desenha a peça no tabuleiro.
* Descrição da interface do módulo: A peça da Torre do xadrez.
* Data da ultima modificação: 27 de Junho de 2019.
*/

#include <iostream>
#include <fstream>
#include "Peca.h"

class Torre : public Peca
{
private:
protected:
public:
	Torre(char simbolo);
	bool checaMovimento(int xAtual, int yAtual, int xDestino, int yDestino);
};
