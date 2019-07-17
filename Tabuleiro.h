/*
* Descrição geral da funcionalidade do módulo: Mostra o tabuleiro e futuramente exibirá e validará os movimentos das peças.
* Descrição da interface do módulo: O tabuleiro que servirá como espaço para o jogo.
* Data da ultima modificação: 24 de Abril de 2019.
*/

#include <iostream>
#include "Posicao.h"
class Tabuleiro
{
private:
	Posicao *casas[8][8];
	bool colisaoDiagonal(int xAtual, int yAtual, int xDestino, int yDestino);
	bool colisaoMais(int xAtual, int yAtual, int xDestino, int yDestino);
protected:
public:
	Tabuleiro();
	Peca *getPeca(int origemL, int origemC);
	void adicionarPeca(Peca *peca, int posicaoInt, int posicaoChar);
	void exibirTabuleiro();
	bool verificaPeca(int origemL, int origemC, bool cor);
	bool checaMovimento(int origemL, int origemC, int destinoL, int destinoC);
	void movimentaPeca(int origemL, int origemC, int destinoL, int destinoC);
};
