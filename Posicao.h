/*
* Descri��o geral da funcionalidade do m�dulo: Cont�m a cor da casa e ter� as coordenadas das pe�as. 
* Descri��o da interface do m�dulo: As casas do tabuleiro.
* Data da ultima modifica��o: 24 de Abril de 2019.
*/

#include "Peca.h"

class Posicao
{
private:
	int linha;
	char coluna;
	//char cor;
	Peca *peca;
public:
	Posicao(int in_linha, int in_coluna);
	bool checaMovimento(int xAtual, int yAtual, int xDestino, int yDestino); //Retorna se o movimento esta correto
	char desenhaPeca(); //Retorna o simbolo da peca na posicao
	bool getPecaCor(); //Retorna a cor da peca na posicao
	int getColuna(); //Retorna a coluna da peca na posicao
	int getLinha(); //Retorna a linha da peca na posicao
	Peca *getPeca(); //Retorna o endereco da peca na posicao
	void setPeca(Peca *pecaAux); //Aponta para a pecaAux como peca que ocupa essa posicao
}; 