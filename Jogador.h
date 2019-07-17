/*
* Descrição geral da funcionalidade do módulo:
* Descrição da interface do módulo:
* Data da ultima modificação:
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
