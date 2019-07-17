/*
* Descri��o geral da funcionalidade do m�dulo:
* Descri��o da interface do m�dulo:
* Data da ultima modifica��o:
*/

#include <string>
#include "Peca.h"
class Jogador
{
private:
	 std::string nomeJogador; //nome do jogador
	 Peca *pecasPossuidas[16]; //pecas que o jogador possui
protected:
public:
	Jogador(std::string nome, Peca **pecas);
	std::string getNome(); //retorna o nome do jogador
};
