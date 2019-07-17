#include "Jogador.h"

Jogador::Jogador(std::string nome, Peca **pecas)
{
	nomeJogador = nome;

	for (int i = 0; i < 16; i = i + 1)
	{
		pecasPossuidas[i] = pecas[i];//**pecas pode apontar a partir de pecas[0](da classe Jogo) ou de pecas[16](da classe Jogo), que são separados de 0 - 15 (pretas) e 16 - 31 (brancas)
	}
}

std::string Jogador::getNome()
{
	return nomeJogador;
}