/*
* Descri��o geral da funcionalidade do m�dulo: A classe 'Jogo' gerenciar� todo o jogo, mas no momento apenas cria o tabuleiro.
* Descri��o da interface do m�dulo: O jogo de xadrez e seus componentes.
* Data da ultima modifica��o: 24 de Abril de 2019.
*/

#include "Tabuleiro.h"
#include "Jogador.h"
#include "Bispo.h"
#include "Torre.h"
#include "Cavalo.h"
#include "Rei.h"
#include "Dama.h"
#include "Peao.h"
#include <limits>
#include <fstream>
#include <ctype.h>


class Jogo {
private:
	Tabuleiro *mesa;
	Jogador *jogadores[2];
	Peca *pecas[32];
	int vez;
	void verificaXeque(Peca *rei);
	bool verificaVitoria(Peca* rei);
	
public:
	Jogo();
	Jogo(std::string nome1, std::string nome2, int vez);
	bool Movimentar(); //recebe as coordenadas da peca, coordenadas para onde pretende ir e verifica se eh valido
	void ExibirTabuleiro(); //mostra o tabuleiro com as pecas nas posicoes

	friend std::ifstream& operator >> (std::ifstream&, Jogo*&);
	friend std::ofstream& operator << (std::ofstream&, Jogo*&);
};
