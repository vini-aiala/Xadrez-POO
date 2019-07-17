/*
* Descri��o geral da funcionalidade do m�dulo: Movimenta-se, verifica se o movimento � v�lido e desenha a pe�a no tabuleiro.
* Descri��o da interface do m�dulo: A pe�a do Pe�o do xadrez.
* Data da ultima modifica��o: 24 de Abril de 2019.
*/
#ifndef pecaGeral
#define pecaGeral

#include <iostream>

class Peca
{
private:
protected:
	bool corPeca;
	char simboloPeca; //simbolo da peca a ser exibido para o usuario
	bool emJogo; //quando true, a peca estara em jogo, quando false, a peca tera sido capturadao
	bool jaMexeu; //indica se a peca ja se mexeu alguma vez (usado para o movimento especial do peao e do rei com a torre)
public:
	virtual bool checaMovimento(int xAtual, int yAtual, int xDestino, int yDestino) = 0; //Verifica se o movimento esta correto
	char desenhaPeca(); //Exibe o simbolo da peca na tela
	bool getCor(); //retorna a cor da peca 1 se for branca e 0 se for preta
	void comida(); //transforma o emJogo em falso assim indicando que nao esta mais presente no jogo
	void mexida();
	bool getEmJogo(); //retorna se a peca esta em jogo
	bool getJaMexeu(); //retorna se flag que indica se j� mexeu
};

#endif